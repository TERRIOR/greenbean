#ifndef NCS_WRAPPER_HEADER
#define NCS_WRAPPER_HEADER
#include "./fp16.h"
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <mvnc.h>
using namespace cv;
void* readGraph(const char* filename, unsigned int* filesize);

class NCSWrapper 
{
public:
    /* Construct wrapper
     * @param input_size: total network input 
     * @param output_size: total network output_size
     */
    NCSWrapper(unsigned int input_num, unsigned int output_num,unsigned int channel_num=3,bool is_mean=false,bool is_scale=false, bool is_verbose=true);
    
    /* Destructor: deallocate all resources 
     */
    ~NCSWrapper();
    
    /* find and open NCS, load graph file, allocate graph
     * @param filename: name of compiled graph file
     * @return: true if success, else false
     */ 
    bool load_file(const char* filename);
    
    /* load data into NCS, get result
     * @param data: pointer to input data
     * @param output: reference to pointer for output data
     * @return: true if success, else false
     */
    bool load_tensor(float* data, float*& output);
    /**
     * @brief setmean
     * @param str
     * 设置均值文件
     */
    void setscale(double scale);
    void setmean(const Mat &mat);
    void setmean(const string &str);
    void process(const Mat &img,Mat &sample_normalized);
    //return code for MVNC functions
    mvncStatus ncsCode;
    //device handle
    void* ncsDevice;
    //device name
    char* ncsName;
    //graph file size
    unsigned int graphSize;
    //graph file buffer
    void* graphData;
    //graph handle
    void* ncsGraph;
    //result size in bytes
    unsigned int resultSize;
    //result buffer (float 16)
    void* result16f;
    //user parameters
    void* otherParam;
    //input buffer (float 16) 
    void* input16f;
    //number of obtained outputs
    unsigned int nres;
    //result buffer (float)
    float* result;
    
    //number of inputs and outputs
    unsigned int n_input, n_output,n_channel;
    
    //if true, output text info to stdout
    bool verbose;
    
    //for destructor
    bool is_init;
    bool is_allocate;
    bool m_ismean;
    bool m_isscale;
    //均值文件
    Mat meanmat;
    double m_dscale;
    //输入大小
    cv::Size input_geometry_;
};

#endif
