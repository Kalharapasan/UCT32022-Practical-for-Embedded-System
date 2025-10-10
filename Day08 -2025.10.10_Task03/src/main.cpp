#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ECHO_PIN = 9;
const int TRIG_PIN = 8;
const int red_LED = 13;
const int yellow_LED = 12;
const int buzzer = 11;

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(red_LED, OUTPUT);
  pinMode(yellow_LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float distance = readDistanceCM();

  if (distance <= 10) {
    digitalWrite(red_LED, HIGH);
    digitalWrite(yellow_LED, LOW);
    tone(buzzer, 1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Object Very Close");
    Serial.print("Measured distance: ");
    Serial.println(distance);
  } else if (distance > 10 && distance <= 20) {
    digitalWrite(red_LED, LOW);
    digitalWrite(yellow_LED, HIGH);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Object Nearby");
    Serial.print("Measured distance: ");
    Serial.println(distance);
  } 
  else {
    digitalWrite(red_LED, LOW);
    digitalWrite(yellow_LED, LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");
    Serial.print("Measured distance: ");
    Serial.println(distance);
  }
  delay(500);
}
