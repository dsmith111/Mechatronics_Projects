int trig = 3;
int echo = 5;
float timet;
int timee;
float range;
int dist2 = 0;
void setup() {
  Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
digitalWrite(trig,LOW);
delay(2);
    //Send out 10 us pulse
     digitalWrite(trig,HIGH);
     delayMicroseconds(10);
     digitalWrite(trig,LOW);
     timee = pulseIn(echo,HIGH);
     int dist1 = ((((timee*0.000001)*340)/2)*100);
     
     if(((((timee*0.000001)*340)/2)*100)<85 && ((((timee*0.000001)*340)/2)*100)>0){
     Serial.println((((timee*0.000001)*340)/2)*100);
     }
     else
     {
Serial.println(dist2);
     
     }

     dist2 = ((((timee*0.000001)*340)/2)*100);
     delay(60);
    
  }

