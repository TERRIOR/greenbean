#include<Arduino.h>
#include <Event.h>
#include <Timer.h>
#include <Servo.h>
#include<stdio.h>
#include<math.h>
#include "stepmotor.h"

/******************************serial*****************************/
String comdata = "";
static bool ifmove=true;
//send
//receive
/*******************************引脚*******************************/
//电机引脚
int motorpin=28;
int motordirpin=30;
int motorenpin=32;
//舵机引脚
int servopin1=22;
int servopin2=24;
int servopin3=26;
/******************************电机参数*****************************/
float motorspeed=80;//速度
stepmotor motor;
/******************************舵机参数****************************/
Servo myservo1,myservo2,myservo3;
//舵机1  排豆舵机
int initangle1=0;
int openangle1=50;
int closeangle1=0;
//舵机2 阀门舵机
int initangle2=65;
int closeangle2=65;
int openangle2=35;
//舵机3 分类舵机
int initangle3=90;
int middleangle=90;
int leftangle=0;
int rightangle=180;
/*******************************函数声明***************************/
void serialpiout();//发送pi信号
void serialpiin();//接收pi信号
/*******************************初始化***************************/
void setup() {
  //引脚初始化
  //舵机部分的初始化 可能需要确定信号范围
  myservo1.attach(servopin1,800,2200);//排豆舵机
  myservo2.attach(servopin2);//阀门舵机
  myservo3.attach(servopin3,800,2200);//分类舵机
  delay(20);
  myservo1.write(initangle1);//+3
  myservo2.write(initangle2);//-2
  myservo3.write(initangle3); //+5
  delay(20);
  //串口初始化
  Serial.begin(9600);
  //步进电机初始化
  motor.motorinit(motorspeed,true,motorpin,motorenpin,motordirpin);
  //定时器初始化
  //FlexiTimer2::set(20, 1.0/1000, movetop); // call every 20 1ms "ticks"
  //FlexiTimer2::start();
}

void loop() {  
  //循环读取串口字符串
  serialpiin();
  //Serial.println(String("servo3"));
}

//pi/pc输入
void serialpiin(){
     while (Serial.available() > 0 )  
    {
      char com=char(Serial.read());
      if(com==' '){
        break;
      }
      comdata += com;
      delay(6); 
    }
    if (comdata.length() > 0)
    {
      int yindex=0;
      int hindex=0;
      int st,s,t;
      //Serial.println(comdata);
      switch(comdata[0]){
        case 'd':
            st=comdata.substring(1).toInt();
            s=st/10;//十位
            t=st%10;//个位
            switch(s){
              case 0:
                if(t==0){
                  myservo1.write(closeangle1);
                  //Serial.println(String("servo1")+":"+closeangle1);
                }else if(t==1){
                  myservo1.write(openangle1);
                  //Serial.println(String("servo1")+":"+openangle1);
                }
              break;
              case 1:
                if(t==0){
                  myservo2.write(closeangle2);
                  //Serial.println(String("servo2")+":"+closeangle2);
                }else if(t==1){
                  myservo2.write(openangle2);
                  //Serial.println(String("servo2")+":"+openangle2);
                }
              break;
              case 2:
                if(t==0){
                  myservo3.write(leftangle);
                  //Serial.println(String("servo3")+":"+leftangle);
                  
                }else if(t==1){
                  myservo3.write(rightangle);
                  //Serial.println(String("servo3")+":"+rightangle);
                }else {
                  myservo3.write(middleangle);
                  //Serial.println(String("servo3")+":"+middleangle);
                }
              break;
              case 3:
                  myservo3.write(leftangle);
                  delay(250);
                  myservo3.write(middleangle);
                  myservo2.write(openangle2);  
                  delay(200);
              break;
              case 4:
                  myservo3.write(rightangle);//分拣盘右转动
                  delay(250);//延时等待到位
                  myservo3.write(middleangle);//分拣盘左移动 
                  myservo2.write(openangle2); //打开阀门舵机
                  delay(200);
              break;
            }
        break;
        case 't':
          st=comdata.substring(1).toInt();
          myservo1.write(st);
        break;
        case 'b':
          st=comdata.substring(1).toInt();
          if(st==0){
            motor.motorstop();
            myservo2.write(closeangle2);
          }else{
            motor.motorrun();
            myservo2.write(openangle2);
          }
        break;
        case 's':
          st=comdata.substring(1).toInt();
          motorspeed=(float)st/100;
          motor.changespeed(motorspeed);
        break;
        //test the angle
        case 'e':
          st=comdata.substring(1).toInt();
          myservo1.write(st);
        break;
        case 'f':
          st=comdata.substring(1).toInt();
          myservo2.write(st);
        break;
        case 'g':
          st=comdata.substring(1).toInt();
          myservo3.write(st);
        break;
      }
      comdata = "";
    }
}



//发送到pc/pi
//void serialpiout(){
//  static int count2=0;
//  count2++; 
//  switch(count2){
//    case 1:
//    if(weigh>0) 
//      //Serial.print(String("")+"w"+(int)weigh);
//    break;
//    case 2:
//    if(weigh_m>0) 
//      //Serial.print(String("")+"m"+(int)weigh_m);
//    break;
//    case 3:
//      //Serial.print(String("")+"f"+(int)waterFlow);
//    break;
//    case 4:
//    if(Input!=0)
//      //Serial.print(String("")+"t"+(int)Input);
//    count2=0;
//    break;
//  }
//}


