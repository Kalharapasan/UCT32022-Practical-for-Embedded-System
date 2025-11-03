#include <Arduino.h>

int xdire = A0;
int ydire = A1;

int lt = 2, lb = 3, ll = 4, lr = 5;

void setup() {
  pinMode(lt, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(ll, OUTPUT);
  pinMode(lr, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(xdire);
  int yValue = analogRead(ydire);

  // Define a dead zone range around 512 (center)
  int deadZone = 100; // Adjust if needed

  // Default: turn off all LEDs
  digitalWrite(lt, LOW);
  digitalWrite(lb, LOW);
  digitalWrite(ll, LOW);
  digitalWrite(lr, LOW);

  // Check X and Y directions
  if (xValue < (512 - deadZone)) {
    digitalWrite(ll, HIGH);
    Serial.println("Left");
  } 
  else if (xValue > (512 + deadZone)) {
    digitalWrite(lr, HIGH);
    Serial.println("Right");
  } 
  else if (yValue < (512 - deadZone)) {
    digitalWrite(lt, HIGH);
    Serial.println("Top");
  } 
  else if (yValue > (512 + deadZone)) {
    digitalWrite(lb, HIGH);
    Serial.println("Bottom");
  } 
  else {
    Serial.println("Center");
  }

  delay(200);
}
