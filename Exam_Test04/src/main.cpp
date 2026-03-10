#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27,16,2);

// 7 LEDs (4th LED index = 3)
int ledPins[7] = {13,12,11,10,9,8,7};

const int servoPin = 3;
const int startButtonPin = 6;
const int luckButtonPin = 5;

int currentLED = 0;
int direction = 1;

int attempts = 0;
int wins = 0;

bool gameStarted = false;

void setup()
{
  for(int i=0;i<7;i++)
  pinMode(ledPins[i],OUTPUT);

  pinMode(startButtonPin,INPUT_PULLUP);
  pinMode(luckButtonPin,INPUT_PULLUP);

  myservo.attach(servoPin);
  myservo.write(0);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Press Start");
}

void loop()
{

  // Start game
  if(!gameStarted)
  {
    if(digitalRead(startButtonPin)==LOW)
    {
      gameStarted=true;
      attempts=0;

      lcd.clear();
      lcd.print("Game Started");
      delay(1000);
    }
    return;
  }

  // Knight rider LED pattern
  for(int i=0;i<7;i++)
  digitalWrite(ledPins[i],LOW);

  digitalWrite(ledPins[currentLED],HIGH);

  delay(120);

  currentLED += direction;

  if(currentLED==6 || currentLED==0)
  direction = -direction;


  // Luck button pressed
  if(digitalRead(luckButtonPin)==LOW)
  {

    delay(200); // debounce

    attempts++;

    if(currentLED == 4) // green LED
    {
      wins++;

      lcd.clear();
      lcd.print("You Win!");
      lcd.setCursor(0,1);
      lcd.print("Score:");
      lcd.print(wins);

      delay(1500);
    }
    else
    {
      lcd.clear();
      lcd.print("You Lose!");
      lcd.setCursor(0,1);
      lcd.print("Try:");
      lcd.print(attempts);

      delay(1500);
    }

    // check game end
    if(wins >= 3)
    {
      lcd.clear();
      lcd.print("Prize Open!");

      myservo.write(90);
      delay(3000);
      myservo.write(0);

      wins=0;
      gameStarted=false;
    }

    else if(attempts >= 3)
    {
      lcd.clear();
      lcd.print("Game Over");
      delay(2000);

      gameStarted=false;
    }

    lcd.clear();
    lcd.print("Press Start");
  }
}