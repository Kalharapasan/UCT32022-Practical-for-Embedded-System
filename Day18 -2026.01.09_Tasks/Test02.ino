#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int flamePin = 7;
int ledPin = 8;
int buzzerPin =9;

void setup() {
  pinMode(flamePin, INPUT);  
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Flame Sensor");
}

void loop() {

  int flameValue = digitalRead(flamePin);

  lcd.setCursor(0, 1);  

  if (flameValue == HIGH) {   
    digitalWrite(ledPin, HIGH);
    Serial.println("Flame Detected");
    digitalWrite(buzzerPin, HIGH);
    lcd.print("Flame Detected ");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Flame");
    digitalWrite(buzzerPin, LOW);
    lcd.print("No Flame       ");
  }

  delay(500);  
}
