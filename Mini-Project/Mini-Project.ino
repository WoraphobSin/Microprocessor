#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int triggerPin = 13;
int echoPin = 12;
int pirpin = 8;
int redpin = 11;
int greenpin = 10;
int bluepin = 9;
int duration,distCM,input1;
bool pir_val;
float weight,old_weight,height,old_height,heightMeter,BMI;
void setup() 
{
    lcd.begin();
    pinMode(triggerPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(pirpin,INPUT);
    pinMode(redpin,OUTPUT);
    pinMode(greenpin,OUTPUT);
    pinMode(bluepin,OUTPUT);
}
void loop() 
{
  pir_val = digitalRead(pirpin);
  if(pir_val == HIGH)
  {
    delay(1500);
    digitalWrite(redpin,HIGH);
    digitalWrite(greenpin,LOW);
    digitalWrite(bluepin,LOW);
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distCM = duration/58;
    if(distCM>200.0)
      {
        height = distCM-200.0;
      }
    else
      {
        height = 200.0-distCM;
      }
    input1 = analogRead(A3);
    weight = map(input1,0,1023,40,120);
    heightMeter = height/100;
    BMI = weight/(heightMeter*heightMeter);
    lcd.home();
    if((old_weight!=weight)||(old_height!=height))
      {
        lcd.clear();
        lcd.print("Height       cm");      
        lcd.setCursor(7,0);
        lcd.print(height);
        lcd.setCursor(0,1);
        lcd.print("Weight       kg");
        lcd.setCursor(7,1);
        lcd.print(weight);
        lcd.setCursor(0,2);
        lcd.print("BMI = ");
        lcd.setCursor(6,2);
        lcd.print(BMI);
        old_weight = weight;
        old_height = height;
      }
  }
  else
  {
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,HIGH);
    digitalWrite(bluepin,LOW);
    
  } 
}
