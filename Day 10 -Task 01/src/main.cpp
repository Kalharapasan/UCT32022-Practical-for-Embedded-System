#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int ledPin= 13;
const int pirPin = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

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