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
static bool ifrun=false;
//send
//receive
/*******************************引脚*******************************/
int gpin=3;
//继电器引脚
int fapin=24;
int dcpin=26;
//电机引脚
int motorpin=5;
int motordirpin=6;
int motorenpin=7;
//舵机引脚
int servopin1=22;

/******************************电机参数*****************************/
float motorspeed=125;//速度
stepmotor motor;
/******************************舵机参数****************************/
Servo myservo1;
//舵机1  排豆舵机
int initangle1=0;
int openangle1=50;
int closeangle1=0;

/*******************************函数声明***************************/
void serialpiout();//发送pi信号
void serialpiin();//接收pi信号
void startselectrun(bool dir);
void callbackstoprun();
void openbeandoor();
void closebeandoor();
void rundcmotor();
void stopdcmotor();
void initmotorstate();
/*******************************初始化***************************/
void setup() {
  //引脚初始化
  pinMode(fapin, OUTPUT);
  pinMode(dcpin, OUTPUT);
  pinMode(gpin, INPUT);
   stopdcmotor();
  //舵机部分的初始化 可能需要确定信号范围
  myservo1.attach(servopin1,800,2200);//排豆舵机
 
  delay(20);
  myservo1.write(initangle1);//+3
  
  delay(20);
  //串口初始化
  Serial.begin(9600);
  //步进电机初始化
  motor.motorinit(motorspeed,true,motorpin,motorenpin,motordirpin);
  motor.motorstop();
  //中断初始化
  //attachInterrupt(digitalPinToInterrupt(gpin),callbackstoprun,RISING);
  //步进电机复位
  initmotorstate();
}

void loop() {  
  //循环读取串口字符串
  serialpiin();
  callbackstoprun();
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
                  Serial.println(String("servo1")+":"+closeangle1);
                }else if(t==1){
                  myservo1.write(openangle1);
                  Serial.println(String("servo1")+":"+openangle1);
                }
              break;
              case 1:
                if(t==0){
                  //阀门关闭
                  //closebeandoor();
                  stopdcmotor();
                }else if(t==1){
                  //阀门开启
                   rundcmotor();
                  //openbeandoor();
                }
              break;
              case 2:
                //原舵机旋转方案
                if(t==0){
                  //myservo3.write(leftangle);
                  //Serial.println(String("servo3")+":"+leftangle);
                  
                }else if(t==1){
                  //myservo3.write(rightangle);
                  //Serial.println(String("servo3")+":"+rightangle);
                }else {
                  //myservo3.write(middleangle);
                  //Serial.println(String("servo3")+":"+middleangle);
                }
              break;
              case 3:
                  //分拣处理1
                  //Serial.println(String("l"));
                  startselectrun(true);
                  //delay(50);//延时等待到位
                  //openbeandoor();
                  rundcmotor();
                  //delay(50);
              break;
              case 4:
                  //分拣处理2
                  //Serial.println(String("r"));
                  startselectrun(false);
                  //delay(50);//延时等待到位
                  //openbeandoor();
                  rundcmotor();
                  //delay(50);
              break;
            }
        break;
        case 'b':
          //控制分拣步进电机
          st=comdata.substring(1).toInt();
          if(st==1){
            startselectrun(true);
          }else if(st==2){
            startselectrun(false);
          }else{
            motor.motorstop();
          }
        break;
        case 'm':
          //控制转盘电机
          st=comdata.substring(1).toInt();
          if(st==1){
            Serial.println(String("dcm run"));
            rundcmotor();
            openbeandoor();
          }else{
            stopdcmotor();
            closebeandoor();
            Serial.println(String("dcm stop"));
          }
        break;
        case 's':
          //调速
          st=comdata.substring(1).toInt();
          motorspeed=(float)st/100;
          motor.changespeed(motorspeed);
        break;
        case 'e':
          //调整角度
          st=comdata.substring(1).toInt();
          myservo1.write(st);
        break;
        
      }
      comdata = "";
    }
}
void startselectrun(bool dir){
	//todo:添加分拣盘步进电机启动转动的代码 方向更改
  motor.changedir(dir);
	motor.motorrun();
  delay(20);
  ifrun=true;
}
void callbackstoprun(){
	//todo:添加停止分拣盘电机运行的代码，放在中断函数中
  //Serial.println(digitalRead(gpin));
  static int s;
  s=digitalRead(gpin);
  if(s==HIGH&&ifrun){
    motor.motorstop();
    Serial.print(String("callback "));
    Serial.println(s);
    ifrun=false;
    
    //delay(10);
  }
  delay(1);
}
void openbeandoor(){
	//todo:添加打开控制阀门的代码，控制继电器
	digitalWrite(fapin, HIGH);
}
void closebeandoor(){
	//todo:添加关闭控制阀门的代码，控制继电器
	digitalWrite(fapin, LOW);
}
void rundcmotor(){
    digitalWrite(dcpin, HIGH);
}
void stopdcmotor(){
    digitalWrite(dcpin, LOW);
}
void initmotorstate(){
    
    motor.runinspeed(50);
    delay(10);
    ifrun=true;
}
