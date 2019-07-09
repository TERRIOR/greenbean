/**
*@projectName   beanselect
*@documentname  mcuworker.h
*@author        zzJun
*@date          20180910
*@brief         管理单片机工作线程的worker类
**/
#ifndef MCUWORKER_H
#define MCUWORKER_H
#include <iostream>
#include <QObject>
#include <QMutex>
#include <QDebug>
#include <QThread>
#ifdef WIN32
#include <windows.h>
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib,"user32.lib")
#endif
#ifdef unix
#include <unistd.h>
#endif
#include "sleep.h"
class mcuworker: public QObject
{
    Q_OBJECT
public:
    mcuworker();
    //请求工作
    void requestWork();
    //结束工作
    void abort();
signals:
    //已经请求
    void workRequested();
    //已经结束工作
    void finished();
    void send();
public slots:
    void doWork();//do something
private :
    bool _abort;//abort:停止 用于停止程序的运行
    bool _working;//是否工作的判断的变量
    QMutex inmutex;//类里变量的锁

};

#endif // MCUWORKER_H
