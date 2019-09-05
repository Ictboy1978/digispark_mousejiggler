#include <DigiMouse.h>

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

#define LED 1

//Minimum and maximum moving time, it will be generated randomly between every NEWPERC time.
#define PERCMIN  48
#define PERCMAX  98

//Generate new percentage every NEWPERC sec.
#define NEWPERC  180

//------------------------------------------------------
void setup(){
  pinMode(LED,OUTPUT);
  digitalWrite(LED,1);
  DigiMouse.begin();
  DigiMouse.delay(1000);
  randomSeed(100);
}
//------------------------------------------------------
void Ledflash()
{
  digitalWrite(LED,1);    
  DigiMouse.delay(250);
  digitalWrite(LED,0);
}
//------------------------------------------------------
void GoDir(u8 dir, u8 spd)
{
  if(dir==0)
  {
    DigiMouse.moveY(spd); 
  }
  if(dir==1)
  {
    DigiMouse.moveY(-spd); 
  }
  if(dir==2)
  {
    DigiMouse.moveX(spd); 
  }
  if(dir==3)
  {
    DigiMouse.moveX(-spd); 
  }
  if(dir==4)
  {
    DigiMouse.moveX(spd);
    DigiMouse.moveY(spd);
  }
  if(dir==5)
  {
    DigiMouse.moveX(spd);
    DigiMouse.moveY(-spd);
  }
  if(dir==6)
  {
    DigiMouse.moveX(-spd);
    DigiMouse.moveY(spd);
  }
  if(dir==7)
  {
    DigiMouse.moveX(-spd);
    DigiMouse.moveY(-spd);
  }
  DigiMouse.delay(40);
}
//------------------------------------------------------
void Jiggle(void)
{
      GoDir(4,1);
      DigiMouse.delay(250);
      GoDir(7,1);
      Ledflash();
}
//------------------------------------------------------
void loop()
{
u16 x, per;
u32 timm;

    for(x=0;x<10;x++) GoDir(0,4);
    for(x=0;x<10;x++) GoDir(2,4);
    for(x=0;x<10;x++) GoDir(1,4);
    for(x=0;x<10;x++) GoDir(3,4);
  
    timm=millis();
    per=PERCMIN+random(PERCMAX-PERCMIN+1);
    
    while(1)
    {
      for(x=0;x<per;x++) Jiggle();
      for(x=0;x<(100-per);x++) DigiMouse.delay(500);
      if((millis()-timm) > 1000*NEWPERC)
      {
              per=PERCMIN+random(PERCMAX-PERCMIN+1);
              timm=millis();
              Ledflash();
      }
    }
}
//------------------------------------------------------

