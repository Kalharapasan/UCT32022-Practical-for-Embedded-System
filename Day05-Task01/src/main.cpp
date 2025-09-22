#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x17,16,2)

void setup() {
  lcd.init();
  lcd.backlight();
  
}

void loop() {

}

