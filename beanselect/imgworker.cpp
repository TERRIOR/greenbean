﻿#include "imgworker.h"

imgworker::imgworker()
{
    _working =false;
    _abort = false;
    m_inited=false;
    QDateTime current_date_time =QDateTime::currentDateTime();
    m_snowtime=current_date_time.toString("MM-dd-hh-mm");
    cout<<m_snowtime.toStdString()<<endl;
    if(classifier==NULL){
        classifier=new Classifier(model_file, trained_file,mean_file,label_file,true);
    }
}

imgworker::~imgworker()
{
    if(classifier!=NULL){
        delete classifier;
        classifier=NULL;
    }
}

bool imgworker::detectimg()
{
    //可以使用vibe进行运动检测，也可以是单纯的帧差法，需要保证第一附图没有任何的干扰物
    const int conscale=0.5;
    cv::Mat scaleimg,hsvimg;
    scaleimg=m_inputmat(cv::Rect(160,50,320,250));
    scalemat(scaleimg,0.5);
    cv::cvtColor(scaleimg,hsvimg,COLOR_BGR2HSV);
    vector<cv::Mat> channelmat;
    cv::split(hsvimg,channelmat);
    if(!m_inited){
        vmat=channelmat.at(1);
//        m_vibe.init(vmat);
//        m_vibe.processFirstFrame(vmat);
        cout << " Training ViBe complete!" << endl;
        m_inited=true;
        return false;
    }
    //m_vibe.testAndUpdate(vmat);
    //cv::Mat mask = m_vibe.getMask();
    //cv::imshow("cc",channelmat.at(1));
    //cv::waitKey(1);
    cv::Mat mask=channelmat.at(1)-vmat;
    mask=mask>50;
    int mask_area = countNonZero(mask);
    cout<<"area:"<<mask_area<<endl;
    if(mask_area<500){
        return false;
    }
    return true;
}


bool  imgworker::locateimg()
{

    //TODO:添加图像处理定位
    cv::Mat scaleimg,grayimg,hsvimg;
    int rectx=160,recty=50;
    scaleimg=m_inputmat(cv::Rect(rectx,recty,320,250));
    cv::cvtColor(scaleimg,hsvimg,cv::COLOR_BGR2HSV);//颜色空间转换
    //cv::cvtColor(scaleimg, graymat, cv::COLOR_RGB2GRAY);//颜色空间转换
    vector<cv::Mat> channelmat;
    cv::split(hsvimg,channelmat);
	blur(channelmat.at(1), grayimg, cv::Size(5, 5));//滤波

//    cv::cvtColor(scaleimg,grayimg,cv::COLOR_BGR2GRAY);//颜色空间转换
    //cv::threshold(grayimg,grayimg,0,255,cv::THRESH_OTSU);//二值化
	//graymask = graymat < 10;
	grayimg=grayimg>80;
	//grayimg = grayimg - graymask;
    //grayimg=255-grayimg;
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(20*scale,20*scale));
    cv::morphologyEx(grayimg, grayimg, cv::MORPH_CLOSE, element);//形态学 闭运算
    //scaleimg.copyTo(dealmat);
    //cv::imshow("yuan",channelmat.at(1));
    //cv::imshow("gray",grayimg);
    //cv::waitKey(1);
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierarcy;
    //CV_RETR_EXTERNAL:只检测多连通区域的外部轮廓
    findContours(grayimg, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    vector<cv::RotatedRect> box(contours.size()); //定义最小外接矩形集合

    if (contours.size() == 0)
    {
        return false;
    }
    cv::Point2f rect[4];
    int count=0;
    int i;
    for(i=0; i<contours.size(); i++)
    {
        double area = contourArea(cv::Mat(contours[i]));
        std::cout<<"area: "<<area<<std::endl;
        //TODO:修改面积的阈值
        if(area<5000*scale*scale)continue;
        box[i] = cv::minAreaRect(cv::Mat(contours[i]));  //计算每个轮廓最小外接矩形
        box[i].points(rect);  //把最小外接矩形四个端点复制给rect数组
        int angle=box[i].angle;
        int line1 = sqrt((rect[1].y-rect[0].y)*(rect[1].y-rect[0].y)+(rect[1].x-rect[0].x)*(rect[1].x-rect[0].x));
        int line2 = sqrt((rect[3].y-rect[0].y)*(rect[3].y-rect[0].y)+(rect[3].x-rect[0].x)*(rect[3].x-rect[0].x));
        int x=line2;//x大于y
        int y=line1;
        if (line1 > line2)
        {
            angle = 90 + angle;
            x=line1;
            y=line2;
        }
        cv::Point2f roi(box[i].center.x+rectx,box[i].center.y+recty);
        imrotate(m_inputmat,m_beanmat,angle,roi);//旋转
        //验证roi范围的合理性
        if(0 <= roi.x && 0 <=x && roi.x + x/2 <=m_beanmat.cols &&
           0 <= roi.y && 0 <=x && roi.y-y/2+x <= m_beanmat.rows&& roi.y*2>x&&roi.x*2>x)
        {
            m_beanmat=m_beanmat(Rect(roi.x-x/2,roi.y-x/2,x,x));//输出为正方形
        }else if(0 <= roi.x && 0 <=x && roi.x + x/2 <=m_beanmat.cols &&
                 0 <= roi.y && 0 <=y && roi.y + y/2 <= m_beanmat.rows&& roi.y*2>y&&roi.x*2>x){
            m_beanmat=m_beanmat(Rect(roi.x-x/2,roi.y-y/2,x,y));//输出为正方形
        }
        count++;
        break;
    }
    if(count ==0||m_beanmat.empty()){
        return false;
    }
    //去除背景
    vector<cv::Mat> channelmat2;
    cv::Mat hsvbean;
    cv::cvtColor(m_beanmat,hsvbean,cv::COLOR_BGR2HSV);
    cv::split(hsvbean,channelmat2);
    cv::Mat mask=channelmat2.at(1)>50;
    cv::Scalar s=cv::mean(m_beanmat,255-mask);
    cv::Mat backimg;
    cv::Mat frontimg;
    m_beanmat.copyTo(frontimg,mask);
    cv::Mat(m_beanmat.size(),CV_8UC3,s).copyTo(backimg,255-mask);
    m_beanmat=backimg+frontimg;
    //cv::imshow("backimg",backimg);
    //cv::imshow("mask",mask);
    cv::imshow("bean",m_beanmat);
    cout<<"find it"<<endl;
    cv::waitKey(1);
    return true;
}

bool imgworker::classifyimg()
{
    //TODO:添加图像分类 此模块分系统进行
    //linux系统运用NCS进行分类
    //win系统运用caffe进行分类
#ifdef WIN32
    cv::Mat classifymat;
    cv::resize(m_beanmat,classifymat,cv::Size(227,227),(0,0),(0,0),3);
    std::vector<Predictionint> predictions = classifier->Classifyint(classifymat);
    /* Print the top N predictions. */
//    for (size_t i = 0; i < predictions.size(); ++i) {
//      Predictionint p = predictions[i];
//      std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
//                << p.first << "\"" << std::endl;
//    }
    if(predictions[0].first==0){
        return true;
    }else{
        return false;
    }
#elif linux
#elif RASPI
#endif
}

void imgworker::savebeanimg(std::string str)
{
    cv::imwrite("./train/bad/"+str+".jpg",m_beanmat);
}

void imgworker::requestWork()
{
    inmutex.lock();
    _working = true;
    _abort = false;
    m_inited=false;
    qDebug()<<"Request worker start in Thread "<<thread()->currentThreadId();
    inmutex.unlock();
    emit workRequested();
}

void imgworker::abort()
{
    inmutex.lock();
    if (_working) {
        _abort = true;
        //把初始化的判断置0，重新开始时再次进行初始化
		m_inited=false;
        qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
    }
    inmutex.unlock();
}

void imgworker::doWork()
{
    while(1){
        inmutex.lock();
        bool abort = _abort;
        inmutex.unlock();
        if (abort) {
            qDebug()<<"Aborting worker process in Thread "<<thread()->currentThreadId();
            break;
        }
        outmutex.lock();
        int size=cvcam->getIcount();
        cvcam->getLastestmat().copyTo(m_inputmat);
        cvcam->jcount();
        outmutex.unlock();
        //size小于0时 说明没有新的图像，不进行图像处理。
        if(size<=0) continue;
        //检测是否有咖啡豆，此处进行高速对比，不需要咖啡豆静止，可以高速检测。
        if(!detectimg()) continue;
        sendstr("d10");//关闭阀门
        //TODO:耗时操作，此处待调整
        Sleep(300);//检测到咖啡豆，等待平稳
        outmutex.lock();
        cvcam->getLastestmat().copyTo(m_inputmat);
        cvcam->jcount();
        outmutex.unlock();
        if(size<=0) continue;
        //定位到咖啡豆
        if(!locateimg()){
            sendstr("d11");//打开阀门
            Sleep(0);
            continue;
        }        
        if(m_btrainmode){
            //训练模式 把咖啡豆的图像保存
            emit sendstr("d30");
            string str=m_snowtime.toStdString();
            string add="Bno";//B=bad G=good N=natual W=wash
            savebeanimg(add+str+to_string(count));
            count++;
        }else{
            //分类模式
            if(classifyimg()){
                //好豆子
                emit sendstr("d30");
            }else{
                //坏豆子
                emit sendstr("d40");
            }
        }
        //TODO:耗时操作，此处待调整
        Sleep(300);
        }
    emit finished();
}
void imgworker::setmode(bool i){
    m_btrainmode=i;
}
bool imgworker::getmode(){
    return m_btrainmode;
}
