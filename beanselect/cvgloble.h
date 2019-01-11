/**
*@projectName
*@documentname  cvgloble.h
*@author        zzJun
*@date          20180422
*@brief         include the opencv function we often use
**/
#ifndef CVGLOBLE_H
#define CVGLOBLE_H
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QImage>
#include <string>
#include <iostream>

using namespace std;
void scalemat(cv::Mat &mat,float scale);
void getimgroi(cv::Mat& mat,const float scale);
QImage Mat2QImage(cv::Mat image1);
void imrotate(cv::Mat& img, cv::Mat& newIm, double angle,cv::Point2f pt);
double Entropy(cv::Mat img);
double getfuza(cv::Mat &img);
void imshowMany(const std::string& _winName, const vector<cv::Mat>& _imgs);

#endif // CVGLOBLE_H
