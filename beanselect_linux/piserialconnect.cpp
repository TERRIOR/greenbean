#include "piserialconnect.h"
#ifdef RASPI
using namespace std;
serialconnect::serialconnect()
{

}
serialconnect::~serialconnect(){

}
bool serialconnect::init(){
   if(wiringPiSetup() < 0)return false;
   else return true;
}

vector<string> serialconnect::getdevicename(){
    vector<string> comstring;
    comstring.push_back(comstr);
    return comstring;
}

bool serialconnect::send(string senddata){
    //requestData.append(tr(senddata.data()));
    serialPrintf(fd,senddata);
    return true;
}

string serialconnect::receive(){
    string data;
    while(serialDataAvail()>0){
            comdata+=char(serialGetchar(fd));
    }
    if(comdata.length()>0)
    {
            cout<<comdata<<endl;
            data=comdata;
            comdata="";
    }
    return data;
}
void serialconnect::start(string com){
    fd = serialOpen(com,9600);
}
void serialconnect::end(){
    my_serialport.close();
}
bool serialconnect::getisstarted(){
    return isstarted;
}
#endif
