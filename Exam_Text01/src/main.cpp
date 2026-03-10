#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDR A0
#define RELAY 7

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {

  pinMode(LDR, INPUT);
  pinMode(RELAY, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Street Light");
  delay(2000);
  lcd.clear();
}

void loop() {

  int ldrValue = analogRead(LDR);

  lcd.setCursor(0,0);
  lcd.print("LDR Value:");
  
  lcd.setCursor(0,1);
  lcd.print(ldrValue);
  lcd.print("   ");

  // Condition from question
  if(ldrValue < 370)
  {
    digitalWrite(RELAY, HIGH);   // Lamp ON
  }
  else
  {
    digitalWrite(RELAY, LOW);    // Lamp OFF
  }

  delay(500);
}