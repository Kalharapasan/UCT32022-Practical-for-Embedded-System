#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

#define IR_RECEIVE_PIN 13
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

int redledPin =2;
int greenledPin =3;
int blueledPin =4;
int buzzerPin =11;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

// Function declarations
void translateIR();
void lcdPrint(const char* text);

void initializeReceiver() {
  // set up the receiver to receive input the NEW way- it changed from earlier versions)
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void initializeLCD() {
  lcd.begin(LCD_COLUMNS, LCD_LINES);
  lcd.print("<press a button>");  // print something.
}

void setup() {
  Serial.begin(9600);
  
  pinMode(redledPin, OUTPUT);
  pinMode(greenledPin, OUTPUT);
  pinMode(blueledPin, OUTPUT);
  // pinMode for buzzer not needed when using tone()
  
  digitalWrite(redledPin, LOW);
  digitalWrite(greenledPin, LOW);
  digitalWrite(blueledPin, LOW);
  
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

void lcdPrint(const char* text) {
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
  Serial.print("Button pressed - Code: ");
  Serial.println(IrReceiver.decodedIRData.command);
  
  switch (IrReceiver.decodedIRData.command) {
    case 48:  // num: 1 - Red LED ON
      digitalWrite(redledPin, HIGH);
      lcdPrint("Red LED ON");
      break;
    case 24:  // num: 2 - Red LED OFF
      digitalWrite(redledPin, LOW);
      lcdPrint("Red LED OFF");
      break;
    case 122:  // num: 3 - Green LED ON
      digitalWrite(greenledPin, HIGH);
      lcdPrint("Green LED ON");
      break;
    case 16:  // num: 4 - Green LED OFF
      digitalWrite(greenledPin, LOW);
      lcdPrint("Green LED OFF");
      break;
    case 56:  // num: 5 - Blue LED ON
      digitalWrite(blueledPin, HIGH);
      lcdPrint("Blue LED ON");
      break;
    case 90:  // num: 6 - Blue LED OFF
      digitalWrite(blueledPin, LOW);
      lcdPrint("Blue LED OFF");
      break;
    case 66:  // num: 7 - Buzzer ON]
      digitalWrite(buzzerPin,HIGH);
      //tone(buzzerPin, 1000, 500);  // 1000Hz for 500ms
      lcdPrint("Buzzer ON");
      break;
    case 74:  // num: 8 - Buzzer OFF
      digitalWrite(buzzerPin,LOW);
      //noTone(buzzerPin);
      lcdPrint("Buzzer OFF");
      break;
    case 82:  // num: 9 - All OFF
      digitalWrite(redledPin, LOW);
      digitalWrite(greenledPin, LOW);
      digitalWrite(blueledPin, LOW);
      noTone(buzzerPin);
      lcdPrint("All OFF");
      break;
    case 104:  // num: 0 - All ON
      digitalWrite(redledPin, HIGH);
      digitalWrite(greenledPin, HIGH);
      digitalWrite(blueledPin, HIGH);
      tone(buzzerPin, 500, 500);  // 500Hz for 500ms
      lcdPrint("All ON");
      break;
    case 162:
      lcdPrint("POWER");
      break;
    case 226:
      lcdPrint("MENU");
      break;
    default:
      lcd.clear();
      lcd.print(IrReceiver.decodedIRData.command);
      lcd.print(" other button");
  }
}