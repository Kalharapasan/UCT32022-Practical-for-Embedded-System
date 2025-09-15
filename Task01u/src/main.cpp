#include <Arduino.h>

const int buttonPin = 13;  
const int ledPin = 12;   
const int buzzerPin=11;  

int buttonState = 0;      

void setup() {
  pinMode(ledPin, OUTPUT);       
  pinMode(buttonPin, INPUT);    
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin,1000);
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(1000);
  }
}
