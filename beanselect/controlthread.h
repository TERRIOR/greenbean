/**
*@projectName   cvcamera
*@documentname  controlthread.h
*@author        zzJun
*@date          20180422
*@brief         control the thread
**/
#ifndef CONTROLTHREAD_H
#define CONTROLTHREAD_H

#include <QObject>
#include "camworker.h"
#include "mcuworker.h"
#include "cvcamera.h"
#include "imgworker.h"
class  controlthread : public QObject
{
    Q_OBJECT
public:
    explicit controlthread(QObject *parent = 0);
    controlthread(bool uicall);
    ~controlthread();
    void stopcamthread();
    void stopimgthread();
    void stopmcuthread();
    void release();
    void startcamthread();
    void startimgthread(bool mode);
    void startmcuthread();
signals:
    void callui();
public slots:
    void refleshmat();

private:

    QThread *camthread;
    QThread *imgthread;
    QThread *mcuthread;
    CamWorker *m_camworker;
    mcuworker *m_pmcuworker;
    imgworker *m_pimgworker;
    bool m_camopened=false;
    bool m_imgopened=false;
    bool m_mcuopened=false;
    bool m_uicall=false;//true:是dialog调用
};

#endif // CONTROLTHREAD_H
