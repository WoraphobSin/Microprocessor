#include "LedControl.h"
LedControl lc=LedControl(5,7,6,1); 
long input,seg0,seg1,seg2,seg3,seg4,seg5,seg6,seg7;
String key;
void show8digit(long num)
{
  seg0=((((((num%10000000)%1000000)%100000)%10000)%1000)%100)%10;
  seg1=((((((num%10000000)%1000000)%100000)%10000)%1000)%100)/10;
  seg2=(((((num%10000000)%1000000)%100000)%10000)%1000)/100;
  seg3=((((num%10000000)%1000000)%100000)%10000)/1000;
  seg4=(((num%10000000)%1000000)%100000)/10000;
  seg5=((num%10000000)%1000000)/100000;
  seg6=(num%10000000)/1000000;
  seg7=num/10000000;
  lc.setDigit(0,0,seg0,false);
  lc.setDigit(0,1,seg1,false);
  lc.setDigit(0,2,seg2,false);
  lc.setDigit(0,3,seg3,false);
  lc.setDigit(0,4,seg4,false);
  lc.setDigit(0,5,seg5,false);
  lc.setDigit(0,6,seg6,false);
  lc.setDigit(0,7,seg7,false);
  delay(200);
}
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
    key=Serial.readString();
    input=key.toInt();
    lc.clearDisplay(0);
    show8digit(input);
  }
}
