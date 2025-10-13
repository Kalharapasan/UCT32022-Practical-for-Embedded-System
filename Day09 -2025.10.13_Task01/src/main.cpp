#include <Arduino.h>

const int temPin =A0;

void setup() {
  pinMode(temPin,INPUT);
  Serial.begin(9600);
  
}
  
void loop() {
  int reding = analogRead(temPin);
  int vol =  reding * (5/100);
  int tem = vol *100;
  Serial.print("Temperature Is : ");
  Serial.print(tem);

}

