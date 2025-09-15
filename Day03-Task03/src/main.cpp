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
    if(command == "LEDON"){
      digitalWrite(ledPin, HIGH);
      // delay(1000);
      Serial.println("LED is ON");
    }else if(command == "LEDOFF"){
      digitalWrite(ledPin, LOW);
      // delay(1000);
      Serial.println("LED is OFF");
    }else{
      Serial.println("Invalid Command");
    }
  }
 
  
}

