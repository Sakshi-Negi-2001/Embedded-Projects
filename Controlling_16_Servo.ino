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
  pwm.setPWMFreq(f);
}

void loop() 
{
  for(int i=0;i<16;i++)
  {
    for(int j=-12;j<=220;j++)
    {
      pwm.setPWM(i,0,Angle(j));
    }
    delay(300);
  }
  for(int i=0;i<16;i++)
  {
    for(int j=220;j>=-12;j--)
    {
      pwm.setPWM(i,0,Angle(j));
    }
    delay(300);
  }
}
int Angle(int angle)
{
  int pw;
  int av;
  pw = map(angle,0,180,mipw,mapw);
  av = int(float(pw)/1000000*f*4096);
  return av;
}
