#include "mcuworker.h"

mcuworker::mcuworker()
{

}

void mcuworker::requestWork()
{
    inmutex.lock();
    _working = true;
    _abort = false;
    qDebug()<<"Request worker start in Thread "<<thread()->currentThreadId();
    inmutex.unlock();
    emit workRequested();
}

void mcuworker::abort()
{
    inmutex.lock();
    if (_working) {
        _abort = true;
        qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
    }
    inmutex.unlock();
}



void mcuworker::doWork()
{
    while(1){
        inmutex.lock();
        bool abort = _abort;
        inmutex.unlock();
        if (abort) {
            qDebug()<<"Aborting worker process in Thread "<<thread()->currentThreadId();
            break;
        }
        g_serialconnect.send();
        //outmutex.lock();
        //TODO:添加运行操作
        //outmutex.unlock();
        //emit imgchange();
        Sleep(0);
    }
    emit finished();
}
