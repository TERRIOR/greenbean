#ifndef SERIALCONNECT_H
#define SERIALCONNECT_H
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <queue>
#include <iostream>
using namespace std;
class serialconnect
{
public:
    serialconnect();
    ~serialconnect();
    void presend(string str);
    void servocontrolvalue(int i,int j);
    bool send();
    string receive();
    vector<string> getdevicename();
    bool start(string com);
    void end();
    bool getisstarted();
    void init();
    void setcom(string com);
    string getcom();
private:
    QSerialPort my_serialport;
    QByteArray requestData;
    queue<string> m_presendstr;
    string m_comstr;
    bool isstarted=false;
    bool m_bsend=false;
};
extern serialconnect g_serialconnect;
#endif // SERIALCONNECT_H
