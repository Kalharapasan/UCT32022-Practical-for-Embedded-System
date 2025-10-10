#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address (commonly 0x27 or 0x3F, depends on module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int redLED = 8;
int greenLED = 9;

void setup() {
  // Start LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LED Status:");

  // Setup LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Turn on Red LED
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  lcd.setCursor(0, 1);
  lcd.print("Red LED ON   ");  // spaces to clear line
  delay(2000);

  // Turn on Green LED
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Green LED ON ");
  delay(2000);
}
