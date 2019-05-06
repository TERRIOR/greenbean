#include "stepmotor.h"
 static void callback( void * arg){
  ((stepmotor*)arg)->pwm();//调用成员函数  
}
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
  m_length=0;
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

void stepmotor::runinspeed(float speed){
  digitalWrite(m_enpin, HIGH);
  float count = 250/(speed);
  Serial.println(count);
  FlexiTimer2::set(count, 1.0/10000, callback,this);
  FlexiTimer2::start();
 }
void stepmotor::pwm(){
  static boolean output = HIGH;
  static float count=0;
  digitalWrite(m_pin, output);
  output = !output;
  m_length++;
  /*
  if(m_length==0){
    count = 250/(m_fspeed);
    FlexiTimer2::set(count+2, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }
  if(m_length==50){
    FlexiTimer2::set(count+1, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }
  if(m_length==100){
    FlexiTimer2::set(count, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }
  if(m_length==1300){
    FlexiTimer2::set(count+1, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }
  if(m_length==1400){
    FlexiTimer2::set(count+2, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }
  if(m_length==1500){
    FlexiTimer2::set(count+3, 1.0/12000, callback,this);
    FlexiTimer2::start();
  }*/
}

void stepmotor::motorrun(){
//        void (*p)();
//        p=stepmotor::pwm;
  m_length=0;
  setmotoren(HIGH);
	float count = 250/(m_fspeed);
  Serial.println(count);
	FlexiTimer2::set(count, 1.0/14000, callback,this);
  FlexiTimer2::start();
}
void stepmotor::motorstop(){
  //digitalWrite(m_enpin, LOW);
	FlexiTimer2::stop();
  digitalWrite(m_pin, LOW);
  Serial.println(m_length);
}
void stepmotor::changedir(bool b){
    m_dir=b;
    if(b){
      digitalWrite(m_dirpin, HIGH);      
    }else{
      digitalWrite(m_dirpin, LOW);
    }
}
void stepmotor::setmotoren(int state){
  if(state!=m_ened){
    digitalWrite(m_enpin, state);
    m_ened=state;
  }  
}
int stepmotor::getenstate(){
  return m_ened;
}
void stepmotor::motorclose(){
  setmotoren(LOW);
  FlexiTimer2::stop();
  digitalWrite(m_pin, LOW);
}
