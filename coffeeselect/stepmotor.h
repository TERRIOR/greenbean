#ifndef stepmotor_h
#define stepmotor_h
#include<stdio.h>
#include<Arduino.h>
#include <Event.h>
#include <Timer.h>
#include "FlexiTimer2.h"

class stepmotor
{
public:
  void motorinit(float speed,int dir,int pin,int enpin,int dirpin);
	int getspeed();
  void runinspeed(float speed);
  void changedir(bool b);
	void setspeed(float speed);
	void changespeed(float speed);
	void motorrun();
	void motorstop();
  void motorclose();
	void pwm();  
  void setmotoren(int state);
  int getenstate();
private:
	//the count of round per second
	float m_fspeed=250;
	bool m_bstate;
  bool m_dir;	
	int m_pin;
  int m_enpin;
  int m_dirpin;
  int m_ened=LOW;
  unsigned long int m_length=0;
  
};
#endif
