#include <LedControl.h>
int DIN = 13;
int CS =  12;
int CLK = 11;
int num;
String key;
LedControl lc=LedControl(DIN,CLK,CS,1);
void setup()
{
  Serial.begin(9600);
  lc.shutdown(0,false);       
  lc.setIntensity(0,3);   
  lc.clearDisplay(0);   
}

void loop()
{ 
  if(Serial.available())
  {
    key = Serial.readString();
    num = key.toInt();
    lc.clearDisplay(0);
    if(num<8)
    {
      for(int i=0;i<num;i++)
      lc.setLed(0,0,i,true);
    }
    if(num>=8&&num<16)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int j=0;j<num-8;j++)
      lc.setLed(0,1,j,true);
    }
    if(num>=16&&num<24)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int j=0;j<num-16;j++)
      lc.setLed(0,2,j,true);
    }
    if(num>=24&&num<32)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int m=0;m<8;m++)
      lc.setLed(0,2,m,true);
      for(int j=0;j<num-24;j++)
      lc.setLed(0,3,j,true);
    }
    if(num>=32&&num<40)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int m=0;m<8;m++)
      lc.setLed(0,2,m,true);
      for(int n=0;n<8;n++)
      lc.setLed(0,3,n,true);
      for(int j=0;j<num-32;j++)
      lc.setLed(0,4,j,true);
    }
    if(num>=40&&num<48)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int m=0;m<8;m++)
      lc.setLed(0,2,m,true);
      for(int n=0;n<8;n++)
      lc.setLed(0,3,n,true);
      for(int o=0;o<8;o++)
      lc.setLed(0,4,o,true);
      for(int j=0;j<num-40;j++)
      lc.setLed(0,5,j,true);
    }
    if(num>=48&&num<56)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int m=0;m<8;m++)
      lc.setLed(0,2,m,true);
      for(int n=0;n<8;n++)
      lc.setLed(0,3,n,true);
      for(int o=0;o<8;o++)
      lc.setLed(0,4,o,true);
      for(int p=0;p<8;p++)
      lc.setLed(0,5,p,true);
      for(int j=0;j<num-48;j++)
      lc.setLed(0,6,j,true);
    }
    if(num>=56&&num<=64)
    {
      for(int i=0;i<8;i++)
      lc.setLed(0,0,i,true);
      for(int k=0;k<8;k++)
      lc.setLed(0,1,k,true);
      for(int m=0;m<8;m++)
      lc.setLed(0,2,m,true);
      for(int n=0;n<8;n++)
      lc.setLed(0,3,n,true);
      for(int o=0;o<8;o++)
      lc.setLed(0,4,o,true);
      for(int p=0;p<8;p++)
      lc.setLed(0,5,p,true);
      for(int q=0;q<8;q++)
      lc.setLed(0,6,q,true);
      for(int j=0;j<num-56;j++)
      lc.setLed(0,7,j,true);
    }
  }
}
