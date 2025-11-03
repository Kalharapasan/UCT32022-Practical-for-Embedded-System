#include <Arduino.h>
#include <Servo.h>
Servo servo;

void setup() {

  servo.attach(3);
  
}

void loop() {

  for(int i =0;i<=180 ;i++){
    servo.write(i);
    delay(100);
  }
 
}