#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define GREEN     12
#define YELLOW    13
#define RED       11
#define BUZZER     5
#define BTN_START  4
#define BTN_FEED   3
#define BTN_PLAY   2

int health    = 70;
int happiness = 50;
bool started  = false;

unsigned long lastUpdate = 0;  // tracks last health drop time

void setup() {
  pinMode(GREEN,  OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED,    OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_FEED,  INPUT_PULLUP);
  pinMode(BTN_PLAY,  INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.print("Press Start...");
}

void loop() {


  if (digitalRead(BTN_START) == LOW) {
    started   = true;
    health    = 70;
    happiness = 50;
    lastUpdate = millis();
    delay(500);  
  }

  if (!started) return;


  if (digitalRead(BTN_FEED) == LOW) {
    health = min(health + 20, 100);
    delay(500); 
  }


  if (digitalRead(BTN_PLAY) == LOW) {
    happiness = min(happiness + 10, 100);
    health    = max(health - 5, 0);
    delay(500); 
  }


  if (millis() - lastUpdate >= 1000) {
    health = max(health - 1, 0);
    lastUpdate = millis();
  }


  if (health <= 30) tone(BUZZER, 1000);
  else              noTone(BUZZER);


  if (health > 70 && happiness > 50) {
    digitalWrite(GREEN, HIGH); digitalWrite(YELLOW, LOW); digitalWrite(RED, LOW);
  } else if (health > 30) {
    digitalWrite(GREEN, LOW); digitalWrite(YELLOW, HIGH); digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW); digitalWrite(YELLOW, LOW); digitalWrite(RED, HIGH);
  }

 
  lcd.clear();
  if (health <= 30) {
    lcd.setCursor(0, 0); lcd.print("Pet is Sad!");
    lcd.setCursor(0, 1); lcd.print("Feed Me!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("H:"); lcd.print(health); lcd.print("% Hap:"); lcd.print(happiness); lcd.print("%");
    lcd.setCursor(0, 1);
    if (health > 70 && happiness > 50) lcd.print("State: Happy :)");
    else if (health > 30)              lcd.print("State: Okay :-|");
    else                               lcd.print("State: Sad :(");
  }

 
}