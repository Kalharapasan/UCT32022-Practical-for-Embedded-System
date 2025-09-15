#include <Arduino.h>
int ledPin =13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Commands : LEDON,LEDOFF");
}

void loop() {


  if(Serial.available() >0){
    String command = Serial.readStringUntil('\n');
    command.trim();
    if(command.equalsIgnoreCase("LEDON")){
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    } else if(command.equalsIgnoreCase("LEDOFF")){
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    } else {
      Serial.println("Unknown Command");
    }
  }
 
  
}

