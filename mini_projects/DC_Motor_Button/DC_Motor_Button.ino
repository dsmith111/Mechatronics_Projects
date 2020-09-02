int dcpin = 3;
int switchpin = 2;
int state = 0;
void setup()
{
  pinMode(switchpin, INPUT);
  pinMode(dcpin, OUTPUT);
  digitalWrite(dcpin,LOW);
}

void loop()
{
  	state = digitalRead(switchpin);
  
(state == 1) ? digitalWrite(dcpin,HIGH) : digitalWrite(dcpin,LOW);
}