#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

const int ledPin= 13;
const int pirPin = 2;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {
 
  lcd.init();
  lcd.backlight();

  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);


}


void loop() {
  int pirState = digitalRead(pirPin);
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("Motion Detected!   ");
    Serial.println("Motion Detected!");
    delay(200);
  } else {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 3);
    lcd.print("No Motion         ");
    Serial.println("No Motion");
    delay(200);
  }
}