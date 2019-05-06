#include "cvcamera.h"


cvcamera *cvcam=NULL;
QMutex outmutex;
cvcamera::cvcamera()
{
    capture=new cv::VideoCapture();
    loadData();
}

cvcamera::~cvcamera()
{
    delete capture;
    capture=NULL;
    cout<<"release cvcam"<<endl;
}

void cvcamera::release()
{
    delete this;
}

int cvcamera::refreshCameraImg()
{
    int size=camimgque.size();
    cout<<size<<endl;
    if(size>0){
        //img=camimgque.front();
        m_mCameraImg=camimgque.front();
        camimgque.pop();
    }else{
        cout<<"queue is empty"<<endl;
    }

    return size;
}

int cvcamera::queuesize()
{
    return camimgque.size();
}

void cvcamera::addcamimg()
{
    if(!m_temp.empty())
        m_temp.copyTo(lastestmat);
    cout<<m_icount<<endl;
//    if(camimgque.size()>max){
//        camimgque.pop();
//        m_icount--;
//    }
//    camimgque.push(lastestmat);
    if(m_icount>max){
        m_icount=max;
    }
    m_icount++;
}
void cvcamera::cap(){
    if(capture->isOpened())
        *capture >> m_temp;
}
bool cvcamera::opencamera()
{

    if(m_iWidth!=-1)
        capture->set(CV_CAP_PROP_FRAME_WIDTH, m_iWidth);//宽度
    if(m_iHight!=-1)
        capture->set(CV_CAP_PROP_FRAME_HEIGHT, m_iHight);//高度
    if(m_iFps!=-1)
        capture->set(CV_CAP_PROP_FPS, m_iFps);//帧数
        cout<<m_iFps<<endl;
    if(m_iBrightness!=-1)
        capture->set(CV_CAP_PROP_BRIGHTNESS, m_iBrightness);//亮度
    if(m_iContrast!=-1)
        capture->set(CV_CAP_PROP_CONTRAST,m_iContrast);//对比度
    if(m_iSaturation!=-1)
        capture->set(CV_CAP_PROP_SATURATION, m_iSaturation);//饱和度
    if(m_iHue!=-1)
        capture->set(CV_CAP_PROP_HUE, m_iHue);//色调
    if(m_iExposure!=-1)
        capture->set(CV_CAP_PROP_EXPOSURE, m_iExposure);//曝光
    if(!capture->isOpened())
        return capture->open(m_iCameraId);
    else return false;
}
int cvcamera::getsize(){
    return camimgque.size();
}

int cvcamera::getIcount() const
{
    return m_icount;
}

void cvcamera::setIcount(int icount)
{
    m_icount = icount;
}

void cvcamera::jcount()
{
    m_icount--;
    if(m_icount<0)m_icount=0;
}
void cvcamera::setcamera(int id, int width, int hight, int fps, int exposure, int brightness, int contrast, int hue, int saturation)
{
    m_iCameraId=id;
    m_iWidth=width;
    m_iHight=hight;
    m_iFps=fps;
    m_iExposure=exposure;
    m_iBrightness=brightness;
    m_iContrast=contrast;
    m_iHue=hue;
    m_iSaturation=saturation;
}

bool cvcamera::closecamera()
{
    if(capture->isOpened()){
        capture->release();
    }else
        return false;
}

void cvcamera::clearqueue()
{
    while (camimgque.size()>10) {
        camimgque.pop();
    }
    cout<<"cleared:  "<<camimgque.size()<<endl;
}

cv::Mat cvcamera::getmCameraImg() const
{
    return m_mCameraImg;
}

void cvcamera::setMCameraImg(const cv::Mat &mCameraImg)
{
    m_mCameraImg = mCameraImg;
}

cv::Mat cvcamera::getlastestimg()
{
    int size=camimgque.size();
    cout<<size<<endl;
    if(size>2){
        return camimgque.back();
    }
    return lastestmat;
}

cv::Mat cvcamera::getLastestmat() const
{
    return lastestmat;
}

int cvcamera::getMax() const
{
    return max;
}

void cvcamera::setMax(int value)
{
    max = value;
}

bool cvcamera::opencamed()
{
    return capture->isOpened();
}

cv::VideoCapture *cvcamera::getCapture() const
{
    return capture;
}
void cvcamera::loadData()
{
    QFile ExpandData(SAVE_DATA);
    if(ExpandData.open(QIODevice::ReadOnly))
    {
        /*文本输出流，用于保存数据*/
        QTextStream In(&ExpandData);
        In >> m_iCameraId;
        In >>m_iWidth;
        In >>m_iHight;
        In >>m_iFps;
        In >>m_iExposure;
        In >>m_iBrightness;
        In >>m_iContrast;
        In >>m_iHue;
        In >>m_iSaturation;
        ExpandData.close();
    }
}


