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
  Serial.print("LDR Value: ");
  Serial.println(sensorRead);
  
 
  if(sensorRead > 800){ 
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON - Dark detected");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF - Light detected");
  }
  
  delay(100);  

}

