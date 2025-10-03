#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int redLED = 12;
const int greenLED = 13;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Function declaration
void updateLCDDisplay();

// Variables
bool redLedState = false;
bool greenLedState = false;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("LED Controller");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
  
  // Turn off both LEDs initially
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  
  updateLCDDisplay();
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    static int state = 0;
    
    switch(state) {
      case 0:
        greenLedState = true;
        redLedState = false;
        break;  
      case 1: 
        greenLedState = false;
        redLedState = true;
        break;
      case 2: 
        greenLedState = true;
        redLedState = true;
        break;
        
      case 3: 
        greenLedState = false;
        redLedState = false;
        break;
    }
    

    // Update LED states
    digitalWrite(greenLED, greenLedState ? HIGH : LOW);
    digitalWrite(redLED, redLedState ? HIGH : LOW);

    updateLCDDisplay();    state = (state + 1) % 4;
  }
}

void updateLCDDisplay() {
  lcd.clear();
  

  lcd.setCursor(0, 0);
  if (greenLedState && redLedState) {
    lcd.print("Both LEDs ON");
  } else if (greenLedState) {
    lcd.print("Green is ON");
  } else if (redLedState) {
    lcd.print("Red is ON");
  } else {
    lcd.print("All LEDs OFF");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("G:");
  lcd.print(greenLedState ? "ON " : "OFF");
  lcd.print(" R:");
  lcd.print(redLedState ? "ON " : "OFF");
}

