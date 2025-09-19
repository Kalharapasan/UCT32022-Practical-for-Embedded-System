#include <Arduino.h>
#include <Keypad.h>

const int ledPIN = 12;
const int buzzerPIN = 13;  


const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; 
byte colPins[COLS] = {6, 5, 4, 3}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(ledPIN, OUTPUT);
  pinMode(buzzerPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Press 1 = LED+Buzzer ON, Press 2 = OFF");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    if (key == '1') {
      digitalWrite(ledPIN, HIGH);
      tone(buzzerPIN, 1000); 
      Serial.println("LED + Buzzer ON");
    }
    else if (key == '2') {
      digitalWrite(ledPIN, LOW);
      noTone(buzzerPIN);
      Serial.println("LED + Buzzer OFF");
    }
  }
}
