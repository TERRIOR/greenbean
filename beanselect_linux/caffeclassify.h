/**
*@documentname  caffeclassify.h
*@author        zzJun
*@date          20180621
*@brief         新增了是否需要均值预处理以及均值处理类型选择
**/
#ifndef CAFFECLASSIFY_H
#define CAFFECLASSIFY_H
#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>
using namespace caffe;  // NOLINT(build/namespaces)
using std::string;
/* Pair (label, confidence) representing a prediction. */
typedef std::pair<string, float> Prediction;
typedef std::pair<int, float> Predictionint;


class Classifier {
 public:
  Classifier(const string& model_file,
             const string& trained_file,
             const string& mean_file,
             const string& label_file,bool pixmean=true);
  Classifier(const string& model_file,
             const string& trained_file,
             const string& label_file,bool pixmean=true);
  std::vector<Prediction> Classify(const cv::Mat& img, int N = 5);
  std::vector<Predictionint> Classifyint(const cv::Mat& img, int N = 5);

  void initcaffe(const std::string &model_file, const std::string &trained_file, const std::string &label_file);
private:
  void SetMean(const string& mean_file);

  std::vector<float> Predict(const cv::Mat& img);

  void WrapInputLayer(std::vector<cv::Mat>* input_channels);

  void Preprocess(const cv::Mat& img,
                  std::vector<cv::Mat>* input_channels);

 private:
  bool needmeanfile=false;
  boost::shared_ptr<Net<float> > net_;
  cv::Size input_geometry_;
  int num_channels_;
  cv::Mat mean_;
  bool m_bpixmean;
  std::vector<string> labels_;
};


#endif // CAFFECLASSIFY_H
