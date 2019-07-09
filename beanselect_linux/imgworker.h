/**
*@projectName   beanselect
*@documentname  imgworker.h
*@author        zzJun
*@date          20180910
*@brief         管理图像处理定位的线程worker类
**/
#ifndef IMGWORKER_H
#define IMGWORKER_H
#ifdef WIN32
#include "header.h"
#include "caffeclassify.h"
#include <windows.h>
#endif
#ifdef unix
#include <unistd.h>
#include <mvnc.h>
#include <ncs_wrapper.hpp>
#endif

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "cvcamera.h"
#include "cvgloble.h"
#include <iostream>
#include <string>
#include <QObject>
#include <QMutex>
#include <qdatetime.h>
#include <QDebug>
#include <QThread>
#include "sleep.h"
#include "Vibe.h"


#define scale 1
#ifdef WIN32
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib,"user32.lib")
#endif

#define NETWORK_INPUT_SIZE  227
#define NETWORK_OUTPUT_SIZE 2

using namespace std;
class imgworker : public QObject
{
    Q_OBJECT
public:
    imgworker();
    ~imgworker();
    /**
     * @brief locateimg locate the point of coffee bean
     * @param input
     * @return 定位咖啡豆
     */
    bool locateimg();
    /**
     * @brief detectimg
     * @return
     * 运动检测，看是否有咖啡豆入内
     */
    bool detectimg();
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
    void sendstr(QString);
public slots:
    void doWork();//do something
private :
    bool _abort;//abort:停止 用于停止程序的运行
    bool _working;//是否工作的判断的变量
    QMutex inmutex;//类里变量的锁
    cv::Mat m_beanmat;
    cv::Mat m_inputmat;
    cv::Mat vmat;
    bool m_bresult;
    bool m_btrainmode=false;
    cv::Point m_plocatepoint;
    QString m_snowtime;
    int count=0;
    ViBe_BGS m_vibe;
    bool m_inited=false;
#ifdef unix
    //string img_file     = "./good.jpg";
    string graph_file     = "./squeezednet.graph";//mobilenet-80ms squeezednet-40ms
    string mean_file     = "./beanmean.jpg";
    NCSWrapper *NCS=NULL;
    bool ncsinited=false;
    Mat resized16f;
    float* result;
#endif
#ifdef WIN32
    Classifier *classifier=NULL;
//    string model_file   = "caffenet.prototxt";
//    string trained_file = "oxford2_iter_30000.caffemodel";
//    string mean_file    = "coffeemean.binaryproto";
    std::string model_file   = "squeezedeploy.prototxt";
    std::string trained_file = "train_iter_37329.caffemodel";
    std::string mean_file    = "coffeemean2.binaryproto";
    std::string label_file   = "lable2.txt";
    std::string img_file     = "./test/bad/1.jpg";
#endif
};

#endif // IMGWORKER_H
