#include <Arduino.h>
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int commonCathodePin = 9;
const byte numbers[10] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};


void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(commonCathodePin, OUTPUT);
  digitalWrite(commonCathodePin, LOW); 
}

void loop() {
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      bool on = bitRead(numbers[i], 7 - j);
      digitalWrite(segmentPins[j], on ? HIGH : LOW);
    }
    delay(1000);
  }

  for (int i = 10; i >0; i--) {
    for (int j = 0; j < 7; j++) {
      bool on = bitRead(numbers[i], 7 - j);
      digitalWrite(segmentPins[j], on ? HIGH : LOW);
    }
    delay(1000);
  }

}