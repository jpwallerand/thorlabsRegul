/*************************************************** 
  This is a library for the Adafruit PT100/P1000 RTD Sensor w/MAX31865

  Designed specifically to work with the Adafruit RTD Sensor
  ----> https://www.adafruit.com/products/3328

  This sensor uses SPI to communicate, 4 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_MAX31865.h>
#include <LiquidCrystal.h>
// Use software SPI: CS, DI, DO, CLK
//Adafruit_MAX31865 max = Adafruit_MAX31865(10, 11, 12, 13);
// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 max = Adafruit_MAX31865(2); //on utilise le hardware SPI et la PIN 2 en CS
const int rs = 14, en = 12, d4 = 16, d5 = 0, d6 = 15, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() {

 

  max.begin(MAX31865_4WIRE);  // set to 2WIRE or 4WIRE as necessary
  //lcd.begin(16, 2);
  // Print a message to the LCD.
 Serial.begin(115200);
}


void loop() {
   max.begin(MAX31865_4WIRE); 
   Serial.println("L1000");
  Serial.println("L?");
  while (Serial.available()>0){
    Serial.print(char(Serial.read()));} 
  delay(3000);
 uint16_t rtd = max.readRTD();

 
  float ratio = rtd;
  ratio /= 32768;
  float temp = max.temperature(RNOMINAL, RREF);
  char tempe[4];
  dtostrf(temp,4,2,tempe);
 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("Mesure: ");
  //lcd.setCursor(0, 1);
 
  lcd.print(tempe);
  lcd.print(" *C");
 
  delay(3000);
 
}
