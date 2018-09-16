#include "controlthread.h"

controlthread::controlthread(QObject *parent) : QObject(parent)
{
    camthread = new QThread();
    m_camworker = new CamWorker();
    m_camworker->moveToThread(camthread);
    connect(m_camworker, SIGNAL(imgchange()),this, SLOT(refleshmat()));//与ui结合时用
    connect(m_camworker, SIGNAL(workRequested()), camthread, SLOT(start()));//1,worker请求，触发thread的start
    connect(camthread, SIGNAL(started()), m_camworker, SLOT(doWork()));//2,start后 dowork(实质工作的地方)
    connect(m_camworker, SIGNAL(finished()), camthread, SLOT(quit()), Qt::DirectConnection);

    imgthread = new QThread();
    m_pimgworker = new imgworker();
    m_pimgworker->moveToThread(imgthread);
    //connect(m_pimgworker, SIGNAL(imgchange()),this, SLOT(refleshmat()));//与ui结合时用
    connect(m_pimgworker, SIGNAL(workRequested()), imgthread, SLOT(start()));//1,worker请求，触发thread的start
    connect(imgthread, SIGNAL(started()), m_pimgworker, SLOT(doWork()));//2,start后 dowork(实质工作的地方)
    connect(m_pimgworker, SIGNAL(finished()), imgthread, SLOT(quit()), Qt::DirectConnection);

    mcuthread = new QThread();
    m_pmcuworker = new mcuworker();
    m_pmcuworker->moveToThread(mcuthread);
    //connect(m_pimgworker, SIGNAL(imgchange()),this, SLOT(refleshmat()));//与ui结合时用
    connect(m_pmcuworker, SIGNAL(workRequested()), mcuthread, SLOT(start()));//1,worker请求，触发thread的start
    connect(mcuthread, SIGNAL(started()), m_pmcuworker, SLOT(doWork()));//2,start后 dowork(实质工作的地方)
    connect(m_pmcuworker, SIGNAL(finished()), mcuthread, SLOT(quit()), Qt::DirectConnection);
}
controlthread::controlthread(bool uicall)
:m_uicall(uicall)
{
    camthread = new QThread();
    m_camworker = new CamWorker();

    m_camworker->moveToThread(camthread);
    //connect(worker, SIGNAL(imgchange()),this, SLOT(refleshmat()));//与ui结合时用
    connect(m_camworker, SIGNAL(workRequested()), camthread, SLOT(start()));//1,worker请求，触发thread的start
    connect(camthread, SIGNAL(started()), m_camworker, SLOT(doWork()));//2,start后 dowork(实质工作的地方)
    connect(m_camworker, SIGNAL(finished()), camthread, SLOT(quit()), Qt::DirectConnection);
}

controlthread::~controlthread()
{
    delete camthread;
    delete mcuthread;
    delete imgthread;
    delete m_pimgworker;
    delete m_pmcuworker;
    delete m_camworker;
    mcuthread=NULL;
    imgthread=NULL;
    camthread=NULL;
    m_pimgworker=NULL;
    m_pmcuworker=NULL;
    m_camworker=NULL;
    cout<<"release control"<<endl;
}

void controlthread::refleshmat()//做监控
{
    int size;
    size= cvcam->queuesize();
    //cout<<"reflesh: "<<size<<endl;
}

void controlthread::stopcamthread()
{
    if(m_camopened){
        m_camworker->abort();
        camthread->wait();
        //qDebug()<<"Deleting thread and worker in Thread "<<this->QObject::thread()->currentThreadId();
        m_camopened=false;
    }
}

void controlthread::stopimgthread()
{
    if(m_imgopened){
        m_pimgworker->abort();
        imgthread->wait();
        //qDebug()<<"Deleting thread and worker in Thread "<<this->QObject::thread()->currentThreadId();
        m_imgopened=false;
    }
}

void controlthread::stopmcuthread()
{
    if(m_mcuopened){
        m_pmcuworker->abort();
        mcuthread->wait();
        //qDebug()<<"Deleting thread and worker in Thread "<<this->QObject::thread()->currentThreadId();
        m_mcuopened=false;
    }
}


void controlthread::startcamthread()
{
    if(!m_camopened){
        m_camworker->abort();
        camthread->wait();
        m_camworker->requestWork();
        m_camopened=true;
    }
}

void controlthread::startimgthread(bool mode)
{
    if(!m_imgopened){
        m_pimgworker->setmode(mode);
        m_pimgworker->abort();
        imgthread->wait();
        m_pimgworker->requestWork();
        m_imgopened=true;
    }
}
void controlthread::startmcuthread()
{
    if(!m_imgopened){
        m_pmcuworker->abort();
        mcuthread->wait();
        m_pmcuworker->requestWork();
        m_mcuopened=true;
    }
}

void controlthread::release()
{
    stopcamthread();
    stopimgthread();
    stopmcuthread();
    delete this;

}
