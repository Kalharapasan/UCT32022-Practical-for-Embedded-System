#include <Arduino.h>
#include <DHT.h>;
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 
LiquidCrystal_I2C lcd(0x27,16,2);

float hum;  
float temp;

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop()
{
    delay(1000);
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print(" % ");
    lcd.setCursor(0,1);
    lcd.print(" Temp: ");
    lcd.print(temp);
    lcd.println(" Celsius");
    delay(1000);
}

