#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DS1302 rtc(2, 3, 4);

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:

}
