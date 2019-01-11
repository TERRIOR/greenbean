#include "stepmotor.h"
 
 int stepmotor::getspeed(){
 	return m_fspeed;
 }

 void stepmotor::setspeed(float speed){
 	m_fspeed=speed;
 }
void stepmotor::motorinit(float speed,int dir,int pin,int enpin,int dirpin){
  m_pin=pin;
  m_dir=dir;
  m_enpin=enpin;
  m_dirpin=dirpin;
  m_fspeed=speed;
  pinMode(m_pin, OUTPUT);
  pinMode(m_enpin, OUTPUT);
  pinMode(m_dirpin, OUTPUT);
  digitalWrite(m_pin, LOW);
  digitalWrite(m_enpin, LOW);
}
// stepmotor::stepmotor(float speed,int pin):m_fspeed(speed),m_pin(pin)
// {
//
// 	
// }

 void stepmotor::changespeed(float speed){
 	setspeed(speed);
 	motorstop();
 	motorrun();
 }

void stepmotor::pwm(){
  static boolean output = HIGH;
  digitalWrite(m_pin, output);
  output = !output;

}
static void callback( void * arg){
  ((stepmotor*)arg)->pwm();//调用成员函数  
}
void stepmotor::motorrun(){
//        void (*p)();
//        p=stepmotor::pwm;
  digitalWrite(m_enpin, HIGH);
	float count = 250/(m_fspeed);
  Serial.println(count);
	FlexiTimer2::set(count, 1.0/10000, callback,this);
  FlexiTimer2::start();
}
void stepmotor::motorstop(){
  digitalWrite(m_enpin, LOW);
	FlexiTimer2::stop();
  digitalWrite(m_pin, LOW);
}
void stepmotor::changedir(bool b){
    m_dir=b;
    if(b){
      digitalWrite(m_dirpin, HIGH);      
    }else{
      digitalWrite(m_dirpin, LOW);
    }
}
