#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

int touchPin = 8;   
int ledPin   = 9;   

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Touch Sensor Test");
}

void loop() {
  int touchState = digitalRead(touchPin);

  lcd.setCursor(0, 1);
  lcd.print("                    "); 

  lcd.setCursor(0, 1);
  if (touchState == HIGH) {
    digitalWrite(ledPin, HIGH);
    lcd.print("Sensor is TOUCHED");
  } else {
    digitalWrite(ledPin, LOW);
    lcd.print("Sensor NOT touched");
  }

  delay(200);
}
