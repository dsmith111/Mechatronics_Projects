#include<Servo.h>

int greenPin = 2;
int yellowPin = 3;
int redPin = 4;
int switchPin = 5;
int piezoPin = A5;
int servoPin = 6;
int numberOfKnocks =0;
float knockVal;
float minKnock = 10;
float maxKnock = 100;
bool locked = false;

Servo servo;

void setup()
{
  for(int i=2;i<5;i++)
  {
   pinMode(i,OUTPUT); 
  }
  servo.attach(servoPin);
  servo.write(0);
  pinMode(switchPin,INPUT);
  pinMode(piezoPin,INPUT);
  digitalWrite(greenPin,HIGH);
Serial.begin(9600);
  
}

void loop()
{
  
  //Read Piezo
 knockVal = analogRead(piezoPin)/4;
  Serial.print(knockVal);
  //Do if locked
 if(locked == true)
 {//If number of knocks are less than requirement but detected, add
   if(numberOfKnocks <3 && validateKnock(knockVal))
   {
     numberOfKnocks++;
     digitalWrite(yellowPin,HIGH);
     delay(250);
     digitalWrite(yellowPin,LOW);
   }
   //If number of knocks are at or above 3, unlock device
   if(numberOfKnocks >=3)
   {
     locked = false;
     servo.write(0);
     digitalWrite(greenPin,HIGH);
     digitalWrite(redPin,LOW);
   }
 }
  //If button pressed, lock
  if(digitalRead(switchPin) == HIGH && locked == false)
     {
       locked = true;
       numberOfKnocks = 0;
       digitalWrite(greenPin,LOW);
       digitalWrite(redPin,HIGH);
       servo.write(90);
	 }
}
     
     //function to check knock
bool validateKnock(int val)
{
 if(val >= minKnock && val <= maxKnock)
 {
   return true;
 }
 else
  {
   return false;
  }
}