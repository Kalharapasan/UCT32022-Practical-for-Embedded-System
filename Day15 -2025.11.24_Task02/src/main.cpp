#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
}

void loop(void){ 
  sensors.requestTemperatures(); 
  lcd.setCursor(0,1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print(" C ");
  lcd.print(sensors.getTempFByIndex(0));
  lcd.print(" F ");

  delay(1000);
}