#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int cursorPos = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  char customKey = keypad.getKey();

  if (customKey) {
    Serial.println(customKey);
    lcd.setCursor(cursorPos, 0);
    lcd.print(customKey);

    cursorPos++;

    if(cursorPos >= 16){
      cursorPos = 0;
      lcd.setCursor(0,1);
    }
  }
}