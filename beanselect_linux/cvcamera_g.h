/**
*@projectName   cvcamera
*@documentname  cvcamera_g.h
*@author        zzJun
*@date          20180422
*@brief         use the cvcamera.dll with this
**/
#ifndef CVCAMERA_G_H
#define CVCAMERA_G_H
#include "controlthread.h"
#include "cvcamera.h"
#include "qdialog.h"
#include "camsetdialog.h"
#include "camworker.h"
#ifdef WIN32
void __stdcall creatcvcam();
cvcamera* __stdcall destroycvcam();
cvcamera* __stdcall getcvcam();
void __stdcall showcamDialog();

controlthread* __stdcall creatimgthread();
#endif
#ifdef unix
void __attribute__((stdcall)) creatcvcam();
cvcamera* __attribute__((stdcall)) destroycvcam();
cvcamera* __attribute__((stdcall)) getcvcam();
void __attribute__((stdcall)) showcamDialog();

controlthread* __attribute__((stdcall)) creatimgthread();

#endif
//extern "C" CVCAMERASHARED_EXPORT void __stdcall destroyimgthread(controlthread* con);
#endif // CVCAMERA_G_H
