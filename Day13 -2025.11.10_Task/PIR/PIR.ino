#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pirPin = 2;      
const int ledPin = 13;     
int pirStat = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("PIR Sensor Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  pirStat = digitalRead(pirPin);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (pirStat == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Object Detected");
    lcd.print("Object Detected");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Object");
    lcd.print("No Object");
  }

  delay(500);
}
