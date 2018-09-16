#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initform();
    creatcvcam();
    tmrTimer = new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this,SLOT(updategui()));
    conthread=creatimgthread();
    initcom();
}

MainWindow::~MainWindow()
{
    conthread->release();
    conthread=NULL;
    delete tmrTimer;
    tmrTimer=NULL;
    cvcam->release();
    delete ui;
}
void MainWindow::initform()
{
    this->location = this->geometry();
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //ui->mainToolBar->hide();
    QString qssFile=":/qss/flatwhite.css";
    QFile file(qssFile);
    if (file.open(QFile::ReadOnly)) {
        QString qss = file.readAll();
        QString paletteColor = qss.mid(20, 7);
        this->setPalette(QPalette(QColor(paletteColor)));
        this->setStyleSheet(qss);
        file.close();
    }

    //showMaximized();
}
void MainWindow::initcom(){
    vector<string> comstring=Serialconnect.getdevicename();
    vector<string>::iterator iterator=comstring.begin();
    ui->com->addItem(tr("none"));
    for(;iterator!=comstring.end();iterator++){
        string com=*iterator;
        ui->com->addItem(tr(com.data()));
    }
}
void MainWindow::on_pushButton_min_clicked()
{
    showMinimized();
}

void MainWindow::on_pushButton_max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
    } else {
        location = this->geometry();
        //ui->centralWidget->showFullScreen();
        this->setGeometry(QApplication::desktop()->availableGeometry());
        this->setProperty("canMove", false);
    }
    max = !max;
}

void MainWindow::on_pushButton_close_clicked()
{
    close();
}
void MainWindow::opencom(){
    if(!g_serialconnect.getisstarted()&&
            ui->com->currentText().toStdString()=="none"){
        if(!g_serialconnect.start(ui->com->currentText().toStdString())){
            //QMessageBox::information(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("打开串口失败"));
            return ;
        }
//        g_serialconnect.send();
        conthread->startmcuthread();//打开mcu线程
        g_serialconnect.presend("b1");
    }
}
void MainWindow::closecom(){
    if(g_serialconnect.getisstarted()){
        g_serialconnect.presend("b0");
        g_serialconnect.end();
        conthread->stopmcuthread();
    }
}
void MainWindow::opencam(){

    if(!cvcam->opencamed()){
        cvcam->opencamera();
        conthread->startcamthread();

    }
}

void MainWindow::closecam(){
    if(cvcam->opencamed()){
        if(conthread!=NULL){
            conthread->stopcamthread();
            cvcam->closecamera();
        }
    }
}
void MainWindow::openimg(){
    if(conthread!=NULL){
        conthread->startimgthread(m_bmode);
    }
}
void MainWindow::closeimg(){
    if(conthread!=NULL){
        conthread->stopimgthread();
    }
}
void MainWindow::updategui()
{
    Mat temp;
    Mat imgshow=cvcam->getLastestmat();
    //Mat imgshow=cvcam->getmCameraImg();
    //std::cout<<"update gui"<<std::endl;
    if(!imgshow.empty()){//先判断指针
        imgshow.copyTo(temp);
        //imshow("da",temp);
        float scalefin,scale1,scale2;
        int matrows=temp.rows;
        int lablerows=ui->lblOriginal->height();
        int matcols=temp.cols;
        int lablecols=ui->lblOriginal->width();
        scale1=(float)lablerows/matrows;
        scale2=(float)lablecols/matcols;
        if(scale1<scale2){
            scalefin=scale1;
        }else{
            scalefin=scale2;
        }
        scalemat(temp,scalefin);
        QImage qimg=Mat2QImage(temp);
        ui->lblOriginal->setPixmap(QPixmap::fromImage(qimg));
    }
}

void MainWindow::on_pushButton_clicked()
{
    //start
    opencam();
    opencom();
    openimg();
    //cvcam->clearqueue();
    if(tmrTimer->isActive() == false){
        tmrTimer->start(20);
    }
    
}


void MainWindow::on_pushButton_stop_clicked()
{
    closecam();
    closecom();
    closeimg();
    if(tmrTimer->isActive()==true){
        tmrTimer->stop();
    }
}

void MainWindow::on_pushButton_pause_toggled(bool checked)
{
    if(!checked){
        if(tmrTimer->isActive()==false){
            tmrTimer->start(20);
        }
        ui->pushButton_pause->setText(QString::fromLocal8Bit("暂停"));
    }else{
        if(tmrTimer->isActive()==true){
            tmrTimer->stop();
        }
        ui->pushButton_pause->setText(QString::fromLocal8Bit("继续"));
    }
}
