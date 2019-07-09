#include "ncs_wrapper.hpp"

using namespace std;

//read whole graph file into buffer, return pointer to buffer, set filesize
void* readGraph(const char* filename, unsigned int* filesize)
{
    ifstream file;
    try
    {
      file.open(filename, ios::binary);
    }
    catch(...)
    {
      return NULL;
    }
    
    file.seekg (0, file.end);
    *filesize = file.tellg();
    file.seekg (0, file.beg);

    char* buffer = new char[*filesize];
    if (file.read(buffer, *filesize))
    {
	file.close();
	return (void*)buffer;
    }
    
    file.close();
    return NULL;
}

NCSWrapper::NCSWrapper(unsigned int input_num, unsigned int output_num,unsigned int channel_num,bool is_mean,bool is_scale,bool is_verbose):
    n_input(input_num),n_output(output_num),n_channel(channel_num),m_ismean(is_mean),
    m_isscale(is_scale),verbose(is_verbose)
{
    //verbose：是否输出结果
    //初始化输入的size
    input_geometry_= cv::Size(n_input,n_input);
    ncsCode = MVNC_OK;
    ncsDevice = NULL;
    ncsName = new char[100];
    graphSize = 0;
    graphData = NULL;
    ncsGraph = NULL;
    resultSize = 0;
    result16f = NULL;
    otherParam = NULL;
    input16f = new unsigned short[n_input*n_input*n_channel];
    nres = 0;
    result = new float[n_output];
    //初始化以及分配设备
    is_init = false;
    is_allocate = false;
}

NCSWrapper::~NCSWrapper()
{
    if(ncsName)
      delete [] ncsName;
    ncsName = NULL;
    if(input16f)
      delete [] (unsigned short*)input16f;
    input16f = NULL;
    if (result)
      delete [] result;
    result = NULL;
    
    if (is_allocate)
    {
	ncsCode = mvncDeallocateGraph(ncsGraph);
	ncsGraph = NULL;
	if (ncsCode != MVNC_OK)
	{
	    if (verbose)
	      cout<<"Cannot deallocate graph: "<<ncsCode<<endl;
	}
    }
    
    if (is_init)
    {
	ncsCode = mvncCloseDevice(ncsDevice);
	ncsDevice = NULL;
	if (ncsCode != MVNC_OK)
	{
	    if (verbose)
	      cout<<"Cannot close NCS device, status: "<<ncsCode<<endl;
	}
    }    
    
    if(graphData)
      delete [] (char*)graphData;
    graphData = NULL;
    
}

bool NCSWrapper::load_file(const char* filename)
{
    //Get NCS name 获取ncs的名字
    ncsCode = mvncGetDeviceName(0, ncsName, 100);
    if (ncsCode != MVNC_OK)
    {
        if (verbose)
	  cout<<"Cannot find NCS device, status: "<<ncsCode<<endl;
        return false;
    }
    if (verbose)
      cout<<"Found device named "<<ncsName<<endl;
    
    //Open NCS device via its name
    ncsCode = mvncOpenDevice(ncsName, &ncsDevice);
    if (ncsCode != MVNC_OK)
    {  
        if (verbose)
	  cout<<"Cannot open NCS device, status: "<<ncsCode<<endl;
        return false;
    }
    if (verbose)
      cout<<"Successfully opened device\n";
    is_init = true;
    
    //Get graph file size and data
    graphData = readGraph(filename, &graphSize);
    if (graphData==NULL)
    {
	if (verbose)
	  cout<<"Cannot open graph file\n";
	return false;
    }
    if (verbose)
      cout<<"Successfully loaded graph file, size is: "<<graphSize<<endl;
    
    //Allocate computational graph 
    //在指定的设备(神经棒)分配graph 并生成一个可以被其他函数调用的句柄
    ncsCode = mvncAllocateGraph(ncsDevice, &ncsGraph, graphData, graphSize);
    if (ncsCode != MVNC_OK)
    {
        if (verbose)
	  cout<<"Cannot allocate graph, status: "<<ncsCode<<endl;
    return false;
    }
    if (verbose)
      cout<<"Successfully allocated graph\n";
    is_allocate = true;
    return true;
}



bool NCSWrapper::load_tensor(float* data, float*& output)
{
    //transform to 16f
    floattofp16((unsigned char*)input16f, data, n_channel*n_input*n_input);
    //load image to NCS 通过NCS在特定的graph上发起推理（即是运算）
    ncsCode = mvncLoadTensor(ncsGraph, input16f, n_channel*n_input*n_input*sizeof(unsigned short), NULL);
    if (ncsCode != MVNC_OK)
    {
	if (verbose)
	  cout<<"Cannot load image to NCS, status: "<<ncsCode<<endl;
	output = NULL;
	return false;
    }
    
    //get result from NCS 获取推理的结果
    ncsCode = mvncGetResult(ncsGraph, &result16f, &resultSize, &otherParam);
    if (ncsCode != MVNC_OK)
    {
	if (verbose)
	  cout<<"Cannot retrieve result from NCS, status: "<<ncsCode<<endl;
	output = NULL;
	return false;
    }
    
    //Check result size 计算输出的类数量
    nres = resultSize/sizeof(unsigned short);
    //n_output是指类别的数量
    if (nres!=n_output)
    {
	if (verbose)
	  cout<<"Output shape mismatch! Expected/Real: "<<n_output<<"/"<<nres<<endl;
	output = NULL;
	return false;
    }
    
    //decode result 转换 为32bit
    fp16tofloat(result, (unsigned char*)result16f, nres);
    
    output = result;
    return true;
}

void NCSWrapper::setmean(const Mat &img)
{
    Mat sample;
    cout<<img.channels()<<" "<<img.type()<<endl;
    if (img.channels() == 3 && n_channel == 1)
    cv::cvtColor(img, sample, cv::COLOR_BGR2GRAY);
    else if (img.channels() == 4 && n_channel == 1)
    cv::cvtColor(img, sample, cv::COLOR_BGRA2GRAY);
    else if (img.channels() == 4 && n_channel == 3)
    cv::cvtColor(img, sample, cv::COLOR_BGRA2BGR);
    else if (img.channels() == 1 && n_channel == 3)
    cv::cvtColor(img, sample, cv::COLOR_GRAY2BGR);
    else
    sample = img;

    cv::Mat sample_resized;
    if (sample.size() != input_geometry_)
    cv::resize(sample, sample_resized, input_geometry_);
    else
    sample_resized = sample;

    cv::Mat sample_float;
    //sample_float=sample_resized;
    if (n_channel == 3)
    sample_resized.convertTo(meanmat, CV_32FC3);
    else
    sample_resized.convertTo(meanmat, CV_32FC1);

}
void NCSWrapper::setscale(double scale){
    m_dscale=scale;
}
void NCSWrapper::setmean(const string &str)
{
    meanmat=imread(str);
}

void NCSWrapper::process(const Mat &img,Mat &sample_normalized)
{
    /* Convert the input image to the input image format of the network. */
    cv::Mat sample;
    cout<<img.channels()<<" "<<img.type()<<endl;
    if (img.channels() == 3 && n_channel == 1)
    cv::cvtColor(img, sample, cv::COLOR_BGR2GRAY);
    else if (img.channels() == 4 && n_channel == 1)
    cv::cvtColor(img, sample, cv::COLOR_BGRA2GRAY);
    else if (img.channels() == 4 && n_channel == 3)
    cv::cvtColor(img, sample, cv::COLOR_BGRA2BGR);
    else if (img.channels() == 1 && n_channel == 3)
    cv::cvtColor(img, sample, cv::COLOR_GRAY2BGR);
    else
    sample = img;

    cv::Mat sample_resized;
    if (sample.size() != input_geometry_)
    cv::resize(sample, sample_resized, input_geometry_);
    else
    sample_resized = sample;

    cv::Mat sample_float;
    //sample_float=sample_resized;
    if (n_channel == 3)
    sample_resized.convertTo(sample_float, CV_32FC3);
    else
    sample_resized.convertTo(sample_float, CV_32FC1);

    //判断是否归一化
    if(m_ismean){
      cv::subtract(sample_float, meanmat, sample_normalized);
      //sample_normalized=sample_float;
    }else{
      sample_float.copyTo(sample_normalized);
    }
    if(m_isscale){
        sample_normalized=sample_normalized*m_dscale;
    }

    /* This operation will write the separate BGR planes directly to the
    * input layer of the network because it is wrapped by the cv::Mat
    * objects in input_channels. */

//    cv::split(sample_normalized, *input_channels);
//    CHECK(reinterpret_cast<float*>(input_channels->at(0).data)
//        == net_->input_blobs()[0]->cpu_data())
//    << "Input channels are not wrapping the input layer of the network.";

}



