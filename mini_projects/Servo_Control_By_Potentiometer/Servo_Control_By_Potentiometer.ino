#include<Servo.h>
Servo servo;
int servopin = 3;
float x = 0;
void setup()
{
 
  servo.attach(servopin);
  servo.write(0);
}

void loop()
{
x= x+25;
  servo.write(x);
delay(250);
}