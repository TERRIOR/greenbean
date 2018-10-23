#include "serialconnect.h"
serialconnect g_serialconnect;
using namespace std;
serialconnect::serialconnect()
{

}
serialconnect::~serialconnect(){

}
void serialconnect::init(){
    
}

void serialconnect::setcom(string com)
{
    m_comstr=com;
}

string serialconnect::getcom()
{
    return m_comstr;
}
vector<string> serialconnect::getdevicename(){
    vector<string> comstring;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        cout<<info.portName().toStdString()<<endl;
        comstring.push_back(info.portName().toStdString());
    }
    return comstring;
}
void serialconnect::servocontrolvalue(int i, int j){
    int code =10*i+j;
    string send="d";
    cout<<code<<send.c_str()<<endl;
    presend(send+to_string(code));
}

void serialconnect::presend(string str){
    m_bsend=true;
    m_presendstr.push(str);
}
bool serialconnect::sendfast(string strtemp){
    //requestData.append(tr(senddata.data()));
    if(isstarted){
        my_serialport.write(strtemp.data());
        return true;
    }
    return false;

}
bool serialconnect::send(){
    //requestData.append(tr(senddata.data()));
    if(isstarted&&m_presendstr.size()>0){
        string strtemp=m_presendstr.front();
        cout<<"send:"<<strtemp<<endl;
        m_presendstr.pop();
        my_serialport.write(strtemp.data());
        m_bsend=false;
        return true;
    }

}

string serialconnect::receive(){
    if(isstarted){
        requestData = my_serialport.readAll();
        string data;
        data=requestData.data();
        requestData.clear();
        return data;
    }

}
bool serialconnect::start(string com){
    m_comstr=com;
    my_serialport.setPortName(QString::fromStdString(com));
    isstarted=my_serialport.open(QIODevice::ReadWrite);
    my_serialport.setBaudRate(9600);
    my_serialport.setDataBits(QSerialPort::Data8);
    my_serialport.setParity(QSerialPort::NoParity);
    my_serialport.setStopBits(QSerialPort::OneStop);
    my_serialport.setFlowControl(QSerialPort::NoFlowControl);
    return isstarted;
}
void serialconnect::end(){
    isstarted=false;
    my_serialport.close();
}
bool serialconnect::getisstarted(){
    return isstarted;
}
