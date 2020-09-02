//Include Libraries
#include <Servo.h>
#include <MFRC522.h>
#include <SPI.h>

//Initial Variable setup

#define cs 10
#define rst 9
#define serv 3
byte readtag[4];
String tag1 = "c7363a4b";
String readtaga;
MFRC522 mfrc522(cs,rst);
Servo servo;

void setup() {
  Serial.begin(9600);
  while(!Serial); //Wait for Serial port to open
  SPI.begin();
  servo.attach(serv);
  mfrc522.PCD_Init();
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
  
}

void loop() {

  servo.write(0);
//Serial.print(tag1);
//If statement to check for tag
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;}
  Serial.println(F("Scan Card: "));
//If Statement to see if card is readable
  if(!mfrc522.PICC_ReadCardSerial()){
      return;
    }    


// For loop to grab data from card
  for(uint8_t i=0;i<4;i++){
    readtag[i]= mfrc522.uid.uidByte[i];
   // Serial.println(readtag[i]);
    readtaga = readtaga+ String(readtag[i],HEX);
  }
Serial.println("");
//Stop Reading
  mfrc522.PICC_HaltA();
  
// Serial.println(readtaga);
//If tag matches, slow blink light
if(tag1 == readtaga){
  /**Serial.print("M Tag: ");
  Serial.println(tag1);
  Serial.print("Read Tag: ");
  Serial.println(readtaga);**/
  Serial.println("Accepted");
  servo.write(180);
delay(1500);
}
//If Tag does not match, blink twice
else if(tag1!=readtaga){
 /** Serial.print("M Tag: ");
  Serial.println(tag1);
  Serial.print("Read Tag: ");
  Serial.println(readtaga);
   **/
   Serial.println("Denied");
   delay(500);
}
//If tag shows error, blink 3 times
else{
  Serial.println("Error");
  delay(500);
}
readtaga = "";
}

