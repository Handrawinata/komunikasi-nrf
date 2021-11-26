#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
}

void loop() {
if(digitalRead(2)==1){
  const char text []= "Hallo ini pesanku!";
  radio.write(&text, sizeof(text));
}
if(digitalRead(3)==1){
  const char text []= "Hello Button 2";
  radio.write(&text, sizeof(text));
}
if(digitalRead(4)==1){
  const char text []= "Hello Button 3";
  radio.write(&text, sizeof(text));
}
//Serial.println(text);
//delay(1000);
}
