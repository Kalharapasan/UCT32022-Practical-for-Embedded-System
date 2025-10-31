#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int redLed =12;
const int greenLed =10;
const int yelloLed=11;

const int buzzerPin =13;

const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int commonCathodePin = 9;
const byte numbers[10] = {
  B11111100, 
  B01100000, 
  B11011010, 
  B11110010, 
  B01100110, 
  B10110110, 
  B10111110, 
  B11100000, 
  B11111110, 
  B11110110  
};

void count (){
  for (int i = 10; i >0; i--) {
    for (int j = 0; j < 7; j++) {
      bool on = bitRead(numbers[i], 7 - j);
      digitalWrite(segmentPins[j], on ? HIGH : LOW);
    }
    delay(1000);
  }

}

void countII (){
  for (int i = 3; i >0; i--) {
    for (int j = 0; j < 7; j++) {
      bool on = bitRead(numbers[i], 7 - j);
      digitalWrite(segmentPins[j], on ? HIGH : LOW);
    }
    delay(1000);
  }

}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(commonCathodePin, OUTPUT);
  digitalWrite(commonCathodePin, LOW); 

  lcd.init();
  lcd.backlight();

  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yelloLed,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

}

void loop(){

  digitalWrite (redLed,HIGH);
  digitalWrite (yelloLed,LOW);
  digitalWrite (greenLed,LOW);
  lcd.setCursor(3, 0);
  lcd.print("STOP");
  count();
  lcd.clear();
  delay(500);

  tone(buzzerPin,500);
  delay(500);
  noTone(buzzerPin);
  digitalWrite (redLed,LOW);
  digitalWrite (yelloLed,HIGH);
  digitalWrite (greenLed,LOW);
  lcd.setCursor(3, 0);
  lcd.print("WAIT");
  countII();
  lcd.clear();
  delay(500);

  digitalWrite (redLed,LOW);
  digitalWrite (yelloLed,LOW);
  digitalWrite (greenLed,HIGH);
  lcd.setCursor(3, 0);
  lcd.print("GO");
  count();
  lcd.clear();
  delay(500);



}

