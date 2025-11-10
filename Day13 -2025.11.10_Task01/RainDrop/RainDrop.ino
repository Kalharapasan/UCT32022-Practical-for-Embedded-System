#include <Servo.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


Servo myservo;

void setup() {
  pinMode(A0, INPUT);

  myservo.attach(9);  
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  
  lcd.setCursor(0, 0);
  lcd.print("Rain Detector");
}

void loop() {
  int x = analogRead(A0);
  Serial.print("Sensor Reading: ");
  Serial.println(x);

  lcd.setCursor(0, 1);

  if (x < 500) {
    Serial.println("No Rain Detected");
    lcd.print("No Rain Detected ");
    myservo.write(180); 
  } else {
    Serial.println("Rain Detected");
    lcd.print("Rain Detected   ");
    myservo.write(90);   
  }

  delay(500);
}
