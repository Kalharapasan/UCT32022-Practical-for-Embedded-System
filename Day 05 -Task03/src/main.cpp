#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pushButton =13;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int x=0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(16, 0);   

  pinMode(pushButton,INPUT);
  
}

void loop() {
  
  int buttonState = digitalRead(13);

  if(buttonState == HIGH){
    x++;
    lcd.clear();
    lcd.print(x);
  }

  

}
