/**
*@projectName   beanselect
*@documentname  imgworker.h
*@author        zzJun
*@date          20180910
*@brief         管理图像处理定位的线程worker类
**/
#ifndef IMGWORKER_H
#define IMGWORKER_H
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "cvcamera.h"
#include "cvgloble.h"
#include <iostream>
#include <QObject>
#include <QMutex>
#include <qdatetime.h>
#include <QDebug>
#include <QThread>
#include <windows.h>
#ifdef RASPI
#include "piserialconnect.h"
#else
#include "serialconnect.h"
#endif
#define scale 0.8
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib,"user32.lib")
class imgworker : public QObject
{
    Q_OBJECT
public:
    imgworker();
    /**
     * @brief locateimg locate the point of coffee bean
     * @param input
     * @return
     */
    bool locateimg();
    /**
     * @brief classifyimg classify the bean
     * @param input
     * @return
     */
    bool classifyimg();
    /**
     * @brief savebeanimg save the img of bean
     */
    void savebeanimg(std::string str);
    //请求工作
    void requestWork();
    //结束工作
    void abort();
    void setmode(bool);
    bool getmode();
signals:
    //已经请求
    void workRequested();
    //已经结束工作
    void finished();
public slots:
    void doWork();//do something
private :
    bool _abort;//abort:停止 用于停止程序的运行
    bool _working;//是否工作的判断的变量
    QMutex inmutex;//类里变量的锁
    cv::Mat m_beanmat;
    cv::Mat m_inputmat;
    bool m_bresult;
    bool m_btrainmode=false;
    cv::Point m_plocatepoint;
    QString m_snowtime;
    int count=0;
};

#endif // IMGWORKER_H
