// Arduino Low Power - Version: Latest #include <LowPower.h>int switchPin = 4;int led = 2;void wakeUp(){  }void setup(){  pinMode(led, OUTPUT);  pinMode(switchPin,INPUT);  attachInterrupt(switchPin,wakeUp,CHANGE);}void loop(){  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);  digitalWrite(led,HIGH);  delay(500);  digitalWrite(led,LOW);  delay(500);  digitalWrite(led,HIGH);  delay(500);  digitalWrite(led,LOW);}