#include <Arduino.h>

const int ldrPin =A0;
const int ledPin =13;
void setup() {
  Serial.begin(9600);
  pinMode(ldrPin,INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {

  int sensorRead = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(sensorRead);
  
  if(sensorRead < 200){ 
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON - Dark detected");
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF - Light detected");
    delay(1000);
  }
  
    

}

