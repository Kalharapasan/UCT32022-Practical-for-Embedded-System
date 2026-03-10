#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo doorServo;

const int greenLEDPin = 10;
const int redLEDPin = 13;
const int servoPin = 11;
const int buzzerPin = 12;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keyPad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";

bool doorOpen = false;

void setup() {

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);


  doorServo.attach(servoPin);
  doorServo.write(90); // Locked

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Door Lock System");
  delay(2000);

  lcd.clear();
  lcd.print("Enter Password");
}

void loop() {

  char key = keyPad.getKey();
  digitalWrite(redLEDPin,HIGH);

  if(key){

  // ENTER PASSWORD
    if(key == '#'){

      if(input == password){

        lcd.clear();
        lcd.print("Access Granted");

        digitalWrite(greenLEDPin,HIGH);
        digitalWrite(redLEDPin,LOW);

        doorServo.write(0); // OPEN
        doorOpen = true;

          delay(1000);

          lcd.clear();
          lcd.print("Door Open");
          lcd.setCursor(0,1);
          lcd.print("Press D to lock");

      }
    else{

      lcd.clear();
      lcd.print("Wrong Password");

      digitalWrite(redLEDPin,HIGH);

      digitalWrite(buzzerPin,HIGH); // BUZZER ON
      delay(2000);
      digitalWrite(buzzerPin,LOW);  // BUZZER OFF

      digitalWrite(redLEDPin,LOW);

      }

    input="";
    delay(1500);

    lcd.clear();
    lcd.print("Enter Password");
  }

  // CLEAR
  else if(key == '*'){

    input="";
    lcd.clear();
    lcd.print("Enter Password");
  }

  // MANUAL LOCK
  else if(key == 'D' && doorOpen){

    lcd.clear();
    lcd.print("Door Locked");

    doorServo.write(90); // LOCK
    doorOpen = false;
    digitalWrite(redLEDPin,HIGH);

    digitalWrite(greenLEDPin,LOW);

    delay(2000);

    lcd.clear();
    lcd.print("Enter Password");
  }

  // PASSWORD INPUT
  else{

    input += key;

    lcd.setCursor(input.length()-1,1);
    lcd.print("*");

  }

  }

}