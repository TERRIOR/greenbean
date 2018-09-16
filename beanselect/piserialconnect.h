#ifndef PISERIALCONNECT_H
#define PISERIALCONNECT_H
#ifdef RASPI

#include <wiringPi.h>
#include <wiringSerial.h>
#include <iostream>
using namespace std;
class serialconnect
{
public:
    serialconnect();
    ~serialconnect();
    bool send(string st);
    string receive();
    bool init();
    vector<string> getdevicename();
    void start();
    void end();
    bool getisstarted();
private:
    int fd;
    string comstr="/dev/ttyACM0";
    string comdata="";
    //QSerialPort my_serialport;
    //QByteArray requestData;
    bool isstarted;
};
#endif

#endif // SERIALCONNECT_H
