#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
Serial.begin(9600);
lcd.begin();
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
lcd.clear();
lcd.setCursor(0,0); lcd.print("Pesan di Terima:");
lcd.setCursor(0,1); lcd.print("Menunggu Pesan!");
}
void loop() {
if (radio.available()) {
//BACA DATA
char text[32] = "";
radio.read(&text, sizeof(text));

//PRINT TO SERIAL
Serial.print("ISI PESAN:");
Serial.println(text);

//PRINT TO LCD
lcd.clear();
lcd.setCursor(0,0); lcd.print("Pesan di Terima:");
lcd.setCursor(0,1);lcd.print(text);
}
}
