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


String inputCode = "";
String password = "1234";

void setup() {
  pinMode(ledPIN, OUTPUT);
  pinMode(buzzerPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter password: 1234 to turn ON, press D to turn OFF");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    if (key == 'D') {
      digitalWrite(ledPIN, LOW);
      noTone(buzzerPIN);
      inputCode = ""; 
      Serial.println("LED + Buzzer OFF");
    }
    else {
      inputCode += key; 
      Serial.print("Current input: ");
      Serial.println(inputCode);

      
      if (inputCode == password) {
        digitalWrite(ledPIN, HIGH);
        tone(buzzerPIN, 1000); 
        Serial.println("Password correct -> LED + Buzzer ON");
        inputCode = ""; 
      }
      else if (inputCode.length() >= password.length()) {
        Serial.println("Wrong password, try again.");
        inputCode = ""; 
      }
    }
  }
}
