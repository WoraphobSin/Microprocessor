#include <Servo.h>
Servo servo;
int num;
void setup() 
{
    Serial.begin(9600);
    servo.attach(9);
}
void loop() 
{
    if(Serial.available())
    {
      num = Serial.read();
      servo.write(num);
      Serial.println(num);
      delay(600);
    }
}
