#-------------------------------------------------
#
# Project created by QtCreator 2018-09-08T21:42:13
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport
#arm版本打开注释
#DEFINES += RASPI
#DEFINES += linux
TARGET = beanselect
TEMPLATE = app
RESOURCES += \
    main.qrc \
    qss.qrc
CONFIG += console
CONFIG += c++11


if(contains(DEFINES,WIN32)){
    DEFINES += NOMINMAX GLOG_NO_ABBREVIATED_SEVERITIES

    DEFINES+=USE_OPENCV
    INCLUDEPATH += E:\caffe\cudainclude\include
    INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include\opencv
    INCLUDEPATH += E:\caffe\caffe\include
    INCLUDEPATH += E:\caffe\caffe\scripts\build
    INCLUDEPATH += E:\caffe\caffe\scripts\build\include
    INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include
    INCLUDEPATH += C:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\include\boost-1_61

    LIBS += -LC:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\lib
    LIBS += -lglog -lgflags  -llmdb -lleveldb  -llmdb
    LIBS += -lsnappy -lcaffehdf5_hl -lcaffehdf5 -lcaffezlib
    LIBS += libopenblas.dll.a

    LIBS += -LC:\Users\zhuojun\.caffe\dependencies\libraries_v120_x64_py27_1.1.0\libraries\lib

    LIBS += -LE:\caffe\boost_1_61_0\lib64-msvc-12.0
    LIBS += -lboost_chrono-vc120-mt-1_61
    LIBS += -lboost_filesystem-vc120-mt-1_61
    LIBS += -lboost_system-vc120-mt-1_61
    LIBS += -lboost_thread-vc120-mt-1_61
    LIBS += -lboost_python-vc120-mt-1_61


    LIBS += -L'C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\lib\x64'
    LIBS += -lcublas -lcublas_device -lcuda -lcudadevrt -lcudart -lcudart_static -lcudnn -lcufft -lcufftw
    LIBS += -lcurand -lcusolver -lcusparse -lnppc -lnppi -lnpps -lnvblas -lnvcuvid -lnvrtc -lOpenCL

    LIBS += -LE:\Anaconda2\libs
    LIBS += -lpython27

    win32:CONFIG(debug, debug|release): {

    LIBS += -LE:\opencv310\opencv\build\x64\vc12\lib
    LIBS += -lopencv_world310d

    LIBS += -LE:\caffe\caffe\scripts\build\lib\Debug
    LIBS += -lcaffe-d -lcaffeproto-d
    LIBS += -llibprotobufd

    } else:win32:CONFIG(release, debug|release): {

    LIBS += -LE:\caffe\caffe\scripts\build\lib\Release
    LIBS += -lcaffe -lcaffeproto

    LIBS += -LE:\opencv310\opencv\build\x64\vc12\lib
    LIBS += -lopencv_world310
    LIBS += -llibprotobuf
    }
    HEADERS  += caffeclassify.h
    SOURCES += caffeclassify.cpp
}




if(contains(DEFINES,linux)) {
SOURCES += ncs_wrapper.cpp \
    fp16.cpp \
   sleep.cpp


HEADERS += \
    fp16.h \
    ncs_wrapper.hpp\
    sleep.h

INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_calib3d.so.2.4.13\
/usr/local/lib/libopencv_core.so.2.4.13\
/usr/local/lib/libopencv_highgui.so.2.4.13\
/usr/local/lib/libopencv_imgproc.so.2.4.13\
/usr/local/lib/libopencv_contrib.so.2.4.13\
/usr/local/lib/libopencv_video.so.2.4.13\
/usr/local/lib/libopencv_objdetect.so.2.4.13\
/usr/local/lib/libopencv_features2d.so.2.4.13
LIBS +=-lmvnc
}

if(contains(DEFINES,RASPI)){
LIBS +=-lwiringPi
}


SOURCES += main.cpp\
        mainwindow.cpp \
    camsetdialog.cpp \
    camworker.cpp \
    controlthread.cpp \
    cvcamera.cpp \
    cvcamera_g.cpp \
    cvgloble.cpp \
    qgloble.cpp \
    mcuworker.cpp \
    imgworker.cpp \
    piserialconnect.cpp \
    serialconnect.cpp \
    Vibe.cpp

HEADERS  += mainwindow.h \
    camsetdialog.h \
    camworker.h \
    controlthread.h \
    cvcamera.h \
    cvcamera_g.h \
    cvgloble.h \
    qgloble.h \
    mcuworker.h \
    imgworker.h \
    piserialconnect.h \
    serialconnect.h \
    Vibe.h

FORMS    += mainwindow.ui \
    camsetdialog.ui
