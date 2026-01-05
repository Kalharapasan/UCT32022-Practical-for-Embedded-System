#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

#define IR_RECEIVE_PIN 2
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

#define BTN_UP   0x2  
#define BTN_DOWN 0x98 
#define BTN_OK   0xA8 

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
int counter = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Counter Application");
  lcd.setCursor(0, 1);
  lcd.print("Counter: 0");
  
  Serial.println("System Ready!");
}

void loop() {
  if (IrReceiver.decode()) {
    uint8_t command = IrReceiver.decodedIRData.command;
    Serial.print("Received command: 0x");
    Serial.println(command, HEX);
    if (command == BTN_UP) {
      counter++;
      Serial.println("UP pressed - Counter increased");
    }
    else if (command == BTN_DOWN) {
      counter--;
      Serial.println("DOWN pressed - Counter decreased");
    }
    else if (command == BTN_OK) {
      counter = 0;
      Serial.println("OK pressed - Counter reset");
    }
    lcd.setCursor(0, 1);
    lcd.print("Counter: ");
    lcd.print(counter);
    lcd.print("   ");
    IrReceiver.resume();
    delay(200);
  }
}

