/**
*@projectName   cvcamera
*@documentname  cvcamera.h
*@author        zzJun
*@date          20180422
*@brief         the class used to control the camera,as well as save the paramster
**/
#ifndef CVCAMERA_H
#define CVCAMERA_H
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <queue>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#define  SAVE_DATA  "CAM_SAVE.zv"

using namespace std;

class  cvcamera
{

public:
    cvcamera();
    ~cvcamera();
    void release();
    //输出Mat
    int refreshCameraImg();
    int queuesize();
    void addcamimg();
    //打开相机
    bool opencamera();
    //设置相机参数
    void setcamera(int id,int width,int hight,int fps,int exposure,int brightness,int constrast,int hub,int saturation);
    //关闭相机
    bool closecamera();
    void clearqueue();
    cv::Mat getmCameraImg() const;
    void setMCameraImg(const cv::Mat &mCameraImg);
    cv::Mat getlastestimg();
    cv::Mat getLastestmat() const;

    int getMax() const;
    void setMax(int value);
    bool opencamed();
    cv::VideoCapture *getCapture() const;

    void loadData();
    void cap();
    int getsize();
    int getIcount() const;
    void setIcount(int icount);
    void jcount();
private:
    int m_iCameraId=0;//相机的识别码 如“0”（暂定）
    cv::VideoCapture *capture;//VideoCapture
    cv::Mat m_mCameraImg;//输出的Mat
    queue<cv::Mat> camimgque;
    int m_iWidth=-1;//图像宽度
    int m_iHight=-1;//图像高度
    int m_iFps=-1;//图像帧数
    int m_iExposure=-1;//图像曝光值
    int m_iBrightness=-1;//图像亮度
    int m_iContrast=-1;//图像对比度
    int m_iHue=-1;//图像色度
    int m_iSaturation=-1;//图像饱和度
    cv::Mat lastestmat;
    cv::Mat m_temp;
    int max=10;
    int m_icount=0;
};


extern  cvcamera *cvcam;
extern  QMutex outmutex;
#endif // OPENCVCAMERA_H
