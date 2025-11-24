#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define ONE_WIRE_BUS 2
#define RELAY_PIN 13
#define TEMP_THRESHOLD 20.0  
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  
  
  sensors.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  
  Serial.println("Temperature Monitor Started");
  Serial.print("Threshold: ");
  Serial.print(TEMP_THRESHOLD);
  Serial.println(" C");
}

void loop(void){ 
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.getTempFByIndex(0);
  lcd.setCursor(0,1);
  lcd.print("                "); 
  lcd.setCursor(0,1);
  lcd.print(tempC, 1); 
  lcd.print("C ");
  lcd.print(tempF, 1);  
  lcd.print("F");

  if (tempC > TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);  
    Serial.print("HIGH TEMP: ");
    Serial.print(tempC);
    Serial.println("C - LED ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);  
    Serial.print("Normal temp: ");
    Serial.print(tempC);
    Serial.println("C - LED OFF");
  }

  delay(1000);
}