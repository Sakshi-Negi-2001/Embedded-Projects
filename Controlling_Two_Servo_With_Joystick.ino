#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int mipw = 650; // Minimum Pulse Width
int mapw = 2350; // Maximum Pulse Width
int dpw = 1500; // Default Pulse Width
int f = 50; // Frequency
uint8_t servonum = 0;
void setup() 
{
  pwm.begin();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  pwm.setPWMFreq(f);
}
void loop() 
{
  pwm.setPWM(0,0,Angle((analogRead(A0))/4));
  pwm.setPWM(1,0,Angle((analogRead(A1))/4));
}
int Angle(int angle)
{
  int pw = map(angle,0,180,mipw,mapw);
  int av = int(float(pw)/1000000*f*4096);
  return av;
}
