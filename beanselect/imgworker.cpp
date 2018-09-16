#include "imgworker.h"

imgworker::imgworker()
{
    _working =false;
    _abort = false;
    QDateTime current_date_time =QDateTime::currentDateTime();
    m_snowtime=current_date_time.toString("MM-dd-hh-mm");
    cout<<m_snowtime.toStdString()<<endl;
}


bool  imgworker::locateimg()
{
    //cv::Point respoint(0,0);
    //TODO:添加图像处理定位
    cv::Mat grayimg;
    scalemat(m_inputmat,scale);//改变图像的大小
    cv::cvtColor(m_inputmat,grayimg,cv::COLOR_BGR2GRAY);//颜色空间转换
    blur(grayimg,grayimg,cv::Size(5,5));//滤波
    cv::threshold(grayimg,grayimg,0,255,cv::THRESH_OTSU);//二值化
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5*scale, 5*scale));
    cv::morphologyEx(grayimg, grayimg, cv::MORPH_CLOSE, element);//形态学 闭运算
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
        if(area<1000*scale*scale||area>10000*scale*scale)continue;
        box[i] = cv::minAreaRect(cv::Mat(contours[i]));  //计算每个轮廓最小外接矩形
        box[i].points(rect);  //把最小外接矩形四个端点复制给rect数组
        int angle=box[i].angle;
        int line1 = sqrt((rect[1].y-rect[0].y)*(rect[1].y-rect[0].y)+(rect[1].x-rect[0].x)*(rect[1].x-rect[0].x));
        int line2 = sqrt((rect[3].y-rect[0].y)*(rect[3].y-rect[0].y)+(rect[3].x-rect[0].x)*(rect[3].x-rect[0].x));
        int x=line2;
        int y=line1;
        if (line1 > line2)
        {
            angle = 90 + angle;
            x=line1;
            y=line2;
        }
        imrotate(m_inputmat,m_beanmat,angle,box[i].center);//旋转
        cv::Point2f roi=box[i].center;
        //验证roi范围的合理性
        if(0 <= roi.x && 0 <= x && roi.x + x <=m_beanmat.cols && 0 <= roi.y && 0 <=y && roi.y + y <= m_beanmat.rows)
        {
            m_beanmat=m_beanmat(Rect(box[i].center.x-x/2,box[i].center.y-y/2,x,y));
        }
        count++;
        break;
    }
    if(count =0||m_beanmat.empty()){
        return false;
    }
    cv::imshow("bean",m_beanmat);
    cv::waitKey(5);
    return true;
}

bool imgworker::classifyimg()
{
    //TODO:添加图像分类 此模块分系统进行
    //linux系统运用NCS进行分类
    //win系统运用caffe进行分类
    return true;
}

void imgworker::savebeanimg(std::string str)
{
    cv::imwrite("./train/"+str+".jpg",m_beanmat);
}

void imgworker::requestWork()
{
    inmutex.lock();
    _working = true;
    _abort = false;
    qDebug()<<"Request worker start in Thread "<<thread()->currentThreadId();
    inmutex.unlock();
    emit workRequested();
}

void imgworker::abort()
{
    inmutex.lock();
    if (_working) {
        _abort = true;
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
        //TODO:添加运行操作
        int size=cvcam->getIcount();
        cvcam->getLastestmat().copyTo(m_inputmat);
        cvcam->jcount();
        outmutex.unlock();
        //size小于0时 说明没有新的图像，不进行图像处理。
        if(size<=0) continue;
        if(locateimg()){

            //定位到咖啡豆
            if(m_btrainmode){
                //训练模式 把咖啡豆的图像保存
                string str=m_snowtime.toStdString();
                savebeanimg(str+to_string(count));
                count++;
            }else{
                //分类模式
                if(classifyimg()){
                    //转动后 回到原点
                    g_serialconnect.servocontrolvalue(2,0);
                    g_serialconnect.servocontrolvalue(2,2);
                }else{
                    //转动后 回到原点
                    g_serialconnect.servocontrolvalue(2,1);
                    g_serialconnect.servocontrolvalue(2,2);
                }
            }
        }
        //emit imgchange();
        Sleep(0);
    }
    emit finished();
}
void imgworker::setmode(bool i){
    m_btrainmode=i;
}
bool imgworker::getmode(){
    return m_btrainmode;
}
