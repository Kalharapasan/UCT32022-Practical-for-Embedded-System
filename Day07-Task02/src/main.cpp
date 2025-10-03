#include <Arduino.h>

const int ldrPin =A0;
const int ledPin =1;


void setup() {
  Serial.begin(9600);
  pinMode(ldrPin,INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {

  int sensorRead = analogRead(ldrPin);
  Serial.println(sensorRead);
  
  if(sensorRead < 500){
    digitalWrite(ledPin, HIGH);
    Serial.print("LED ON");
  } else {
    digitalWrite(ledPin, LOW);
      Serial.print("LED OFF");
  }
  
  delay(100);

}

