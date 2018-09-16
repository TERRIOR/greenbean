#-------------------------------------------------
#
# Project created by QtCreator 2018-09-08T21:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport
#arm版本打开注释
#DEFINES += RASPI
TARGET = beanselect
TEMPLATE = app
RESOURCES += \
    main.qrc \
    qss.qrc


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
    serialconnect.cpp

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
    serialconnect.h

FORMS    += mainwindow.ui \
    camsetdialog.ui


win32 {
INCLUDEPATH += E:\opencv\opencv\build\include\opencv2
INCLUDEPATH += E:\opencv\opencv\build\include\opencv
INCLUDEPATH += E:\opencv\opencv\build\include
}
win32:CONFIG(debug, debug|release): {

LIBS += -LE:\opencv\opencv\build\x64\vc12\lib \
-lopencv_objdetect2412d\
-lopencv_ts2412d\
-lopencv_video2412d\
-lopencv_nonfree2412d\
-lopencv_ocl2412d\
-lopencv_photo2412d\
-lopencv_stitching2412d\
-lopencv_superres2412d\
-lopencv_videostab2412d\
-lopencv_calib3d2412d\
-lopencv_contrib2412d\
-lopencv_core2412d\
-lopencv_features2d2412d\
-lopencv_flann2412d\
-lopencv_gpu2412d\
-lopencv_highgui2412d\
-lopencv_imgproc2412d\
-lopencv_legacy2412d\
-lopencv_ml2412


} else:win32:CONFIG(release, debug|release): {
LIBS += -LE:\opencv\opencv\build\x64\vc12\lib \
-lopencv_objdetect2412 \
-lopencv_ts2412 \
-lopencv_video2412 \
-lopencv_nonfree2412 \
-lopencv_ocl2412 \
-lopencv_photo2412 \
-lopencv_stitching2412 \
-lopencv_superres2412 \
-lopencv_videostab2412 \
-lopencv_calib3d2412 \
-lopencv_contrib2412 \
-lopencv_core2412 \
-lopencv_features2d2412 \
-lopencv_flann2412 \
-lopencv_gpu2412 \
-lopencv_highgui2412 \
-lopencv_imgproc2412 \
-lopencv_legacy2412 \
-lopencv_ml2412

}

unix {
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
LIBS +=-lwiringPi
LIBS += /usr/local/lib/libopencv_calib3d.so.2.4.13\
/usr/local/lib/libopencv_core.so.2.4.13\
/usr/local/lib/libopencv_highgui.so.2.4.13\
/usr/local/lib/libopencv_imgproc.so.2.4.13\
/usr/local/lib/libopencv_contrib.so.2.4.13\
/usr/local/lib/libopencv_video.so.2.4.13\
/usr/local/lib/libopencv_objdetect.so.2.4.13\
/usr/local/lib/libopencv_features2d.so.2.4.13
}
