#include <Arduino.h>

const int buzzerPIN = 13;   
const int ledPIN = 12;

void setup() {
  pinMode(buzzerPIN, OUTPUT);
  pinMode(ledPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Commands : LEDON,LEDOFF,BUZZERON,BUZZEROFF");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LEDON") {
      digitalWrite(ledPIN, HIGH);
      Serial.println("LED is ON");
    }
    else if (command == "LEDOFF") {
      digitalWrite(ledPIN, LOW);
      Serial.println("LED is OFF");
    }
    else if (command == "BUZZERON") {
      // If passive buzzer → use tone
      tone(buzzerPIN, 1000);  // 1kHz tone
      Serial.println("Buzzer is ON");
    }
    else if (command == "BUZZEROFF") {
      noTone(buzzerPIN); // stop tone
      Serial.println("Buzzer is OFF");
    }
    else {
      Serial.println("Unknown Command");
    }
  }
}
