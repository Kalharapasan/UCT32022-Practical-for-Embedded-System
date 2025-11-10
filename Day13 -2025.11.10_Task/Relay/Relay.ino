#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int rainSensorPin = A0;  
const int relayPin = 13;       

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Rain Detector");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(rainSensorPin);
  Serial.print("Sensor Reading: ");
  Serial.println(sensorValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Rain Detector");

  lcd.setCursor(0, 1);

  if (sensorValue > 500) {
    Serial.println("No Rain Detected");
    lcd.print("No Rain Detected ");
    digitalWrite(relayPin, LOW);   
  } else {
    Serial.println("Rain Detected");
    lcd.print("Rain Detected   ");
    digitalWrite(relayPin, HIGH);  
  }

  delay(1000); 
}
