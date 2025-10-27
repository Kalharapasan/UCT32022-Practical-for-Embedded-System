#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int ledPin = 13;
const int buzzerPin = 12;
const int pirPin = 2;

const int SCREEN_WIDTH = 128; 
const int SCREEN_HEIGHT = 64; 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32/64 displays
    Serial.println(F("SSD1306 allocation failed"));
    while(true);
  }
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);

}

void loop() {
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    display.clearDisplay();
    display.setTextSize(2);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(0,10);     
    display.println("Motion Detected!");
    display.display(); 
    Serial.println("Motion Detected!");          

    delay(2000); 
  } 
  else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    display.clearDisplay();
    display.setTextSize(2);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(0,10);     
    display.println("No Motion");
    display.display();  
    Serial.println("No Motion");         

    delay(2000); 
  }
 
}
