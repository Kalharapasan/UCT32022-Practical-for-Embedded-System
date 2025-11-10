#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int irSensorPin = 7;  // IR sensor output pin
const int ledPin = 13;      // Onboard LED

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("IR Sensor Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  lcd.clear();  
  lcd.setCursor(0, 0);

  if (sensorValue == LOW) {
    lcd.print("Obstacle Detected!");
    digitalWrite(ledPin, HIGH);
    Serial.println("Obstacle detected!");
  } else {
    lcd.print("No Obstacle");
    digitalWrite(ledPin, LOW);
    Serial.println("No obstacle.");
  }

  delay(500);
}
