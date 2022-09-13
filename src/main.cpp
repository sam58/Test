/* Digispark ATtiny85 to small OLED 128x32 by I2C
 * https://github.com/datacute/Tiny4kOLED 
 * Tiny4kOLED.h: SSD1306xLED-Drivers for OLED 128x32 displays
 * @created: 2014-08-12  @author: Neven Boyanov
 * Source code available at: https://bitbucket.org/tinusaur/ssd1306xled
 * @ modified for 16x32 fonts: 2017-01-12 @author: Mihai Valentin Predoi 
 * Fits (2944 bytes) into Digispark  ATtiny85 (6012 bytes). 52 bytes of dynamic memory.
 *  ATtiny85(DigiSpark)			OLED
 *    <<------------------------>>
 *  PB0(DigiSpark P0)        	SDA
 *  PB2(DigiSpark P2)        	SCL
 *  5V         					VCC
 *  GND        					GND
 * 
 * FILE: dht.h
 * AUTHOR: Rob Tillaart
 * VERSION: 0.2.4
 * PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
 * URL: https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTstable 
 *
 *	ATtiny85(DigiSpark)			DHT12
 *    <<------------------------>>
 *  DigiSpark P3	        	SDA
 *  GND				        	SCL
 *  5V         					VCC
 *  GND        					GND
 * 
 */

#include <Tiny4kOLED.h>
#include <TinyWireM.h>
#include <dht.h>

// ============================================================================

dht DHT12;
#define DHT12_PIN 3

void setup() {
  pinMode(3, INPUT); //Read DHT12 on P3 
  oled.begin();
  oled.on();
}

void loop() {
  
  oled.clear(); //all black
  oled.setFont(FONT8X16); // 2 lines of 16 characters exactly fills 128x32
  
  //next line: oled.setCursor(X IN PIXELS, Y - NO EFFECT since 32 bits is max height);
  oled.setCursor(0, 0);
  
  //oled.print(F(DHT_LIB_VERSION)); //wrap strings in F() to save RAM!

  // READ DATA
  int chk = DHT12.read12(DHT12_PIN);

  oled.print(DHT12.temperature, 1);

  delay(15000); //Change the delay to how often read the data.
}