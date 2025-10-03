#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define RED_LED_PIN 1
#define GREEN_LED_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Function declaration
void updateLCDDisplay();

bool redLedState = false;
bool greenLedState = false;
unsigned long previousMillis = 0;
const long interval = 2000; 

void setup() {

  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LED Controller");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  
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
    

    digitalWrite(GREEN_LED_PIN, greenLedState ? HIGH : LOW);
    digitalWrite(RED_LED_PIN, redLedState ? HIGH : LOW);

    updateLCDDisplay();
    
    state = (state + 1) % 4;
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

