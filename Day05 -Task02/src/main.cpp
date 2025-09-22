#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(16, 0);   
  lcd.print("Hello Kalhara");
}

void loop() {
  
  for (int i = 0; i < 16 + 12; i++) { 
    lcd.scrollDisplayLeft();
    delay(250);
  }

  delay(500); 

 
  lcd.clear();
  lcd.setCursor(16, 0);   
  lcd.print("Hello Kalhara");


}
