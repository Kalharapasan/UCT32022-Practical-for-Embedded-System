#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(3,0);
  lcd.print("Hello");
  lcd.setCursor(6,01);
  lcd.print("Human");


}

void loop() {
  

}
