#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 13       
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); 
}

void loop() {
  delay(2000); 

  float temp = dht.readTemperature(); 
  float hum = dht.readHumidity();     

  if (isnan(temp) || isnan(hum)) { 
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");
}
