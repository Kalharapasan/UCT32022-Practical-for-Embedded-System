#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

#define IR_RECEIVE_PIN 2
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void initializeReceiver() {
  // set up the receiver to receive input the NEW way- it changed from earlier versions)
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void initializeLCD() {
  lcd.begin(16, 2);   // 16 columns, 2 rows.
  lcd.print("<press a button>");  // print something.
}

void setup() {
  initializeReceiver();
  initializeLCD();
}

void loop() {
  // Checks received an IR signal
  if (IrReceiver.decode()) {
    translateIR(); // calls our translate function
    IrReceiver.resume();  // Receive the next value
  }
}

void lcdPrint(char* text) {
  lcd.clear();
  lcd.setCursor(0, 0); // set cursor for text to print in top left row/column
  lcd.print("button pressed:");
  lcd.setCursor(0, 1); // move cursor to print to next line.
  lcd.print(text);
  lcd.print(" code: ");
  lcd.print(IrReceiver.decodedIRData.command);
}

void translateIR() {
  // Takes command based on IR code received
  switch (IrReceiver.decodedIRData.command) {
    case 162:
      lcdPrint("POWER");
      break;
    case 226:
      lcdPrint("MENU");
      break;
    case 34:
      lcdPrint("TEST");
      break;
    case 2:
      lcdPrint("PLUS");
      break;
    case 194:
      lcdPrint("BACK");
      break;
    case 224:
      lcdPrint("PREV.");
      break;
    case 168:
      lcdPrint("PLAY");
      break;
    case 144:
      lcdPrint("NEXT");
      break;
    case 104:
      lcdPrint("num: 0");
      break;
    case 152:
      lcdPrint("MINUS");
      break;
    case 176:
      lcdPrint("key: C");
      break;
    case 48:
      lcdPrint("num: 1");
      break;
    case 24:
      lcdPrint("num: 2");
      break;
    case 122:
      lcdPrint("num: 3");
      break;
    case 16:
      lcdPrint("num: 4");
      break;
    case 56:
      lcdPrint("num: 5");
      break;
    case 90:
      lcdPrint("num: 6");
      break;
    case 66:
      lcdPrint("num: 7");
      break;
    case 74:
      lcdPrint("num: 8");
      break;
    case 82:
      lcdPrint("num: 9");
      break;
    default:
      lcd.clear();
      lcd.print(IrReceiver.decodedIRData.command);
      lcd.print(" other button");
  }
}