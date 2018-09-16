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
    presend("d"+code);
}

void serialconnect::presend(string str){
    m_bsend=true;
    m_presendstr.push(str);
}

bool serialconnect::send(){
    //requestData.append(tr(senddata.data()));
    if(isstarted&&m_presendstr.size()>0){
        my_serialport.write(m_presendstr.back().c_str());
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
    my_serialport.setPortName(QString::fromStdString(com));
    my_serialport.setBaudRate(115200);
    my_serialport.setDataBits(QSerialPort::Data8);
    my_serialport.setParity(QSerialPort::NoParity);
    my_serialport.setStopBits(QSerialPort::OneStop);
    my_serialport.setFlowControl(QSerialPort::NoFlowControl);
    isstarted=my_serialport.open(QIODevice::ReadWrite);
    return isstarted;
}
void serialconnect::end(){
    my_serialport.close();
}
bool serialconnect::getisstarted(){
    return isstarted;
}
