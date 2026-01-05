#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
int greenLed = 12;
int redLed=11;

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long irCode = IrReceiver.decodedIRData.decodedRawData;
    
    Serial.print("IR Code: 0x");
    Serial.println(irCode, HEX);
    
    // Change these codes to match your remote buttons
    if (irCode ==  0xCF30FF00) {  // Green LED ON
      digitalWrite(greenLed, HIGH);
      Serial.println("Green LED ON");
    }
    else if (irCode == 0xE718FF00) {  // Green LED OFF
      digitalWrite(greenLed, LOW);
      Serial.println("Green LED OFF");
    }
    else if (irCode == 0x857AFF00) {  // Red LED ON
      digitalWrite(redLed, HIGH);
      Serial.println("Red LED ON");
    }
    else if (irCode == 0xC738FF00) {  // Red LED OFF
      digitalWrite(redLed, LOW);
      Serial.println("Red LED OFF");
    }
    
    IrReceiver.resume();
  }
}

