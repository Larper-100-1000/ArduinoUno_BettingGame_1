#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int NumLeds = 5;
const int PinLeds[NumLeds] = {2,3,4,5,6};
const int PinJoystick = 13;
const int PinJoystickX = A1;

const int JOYX_LEFT = 400;
const int JOYX_RIGHT = 623;

long randNumber;
long moneyEarnings;
long totalMoney;
long betAmount;

void setup(){
  betAmount = 1;
  totalMoney = 10;

  lcd.begin(16,2);
  for(int i = 0; i < NumLeds; i++){
    pinMode(PinLeds[i], OUTPUT);
  }
  pinMode(PinJoystick, INPUT);
  digitalWrite(PinJoystick, HIGH);
  randomSeed(analogRead(0));
}

void loop(){
  int xVal = analogRead(PinJoystickX);
  if(xVal < JOYX_LEFT && betAmount > 1){
    betAmount -= 1;
    delay(500);
  } 
  else if(xVal > JOYX_RIGHT){
    betAmount += 1;
    delay(500);
  }

  lcd.setCursor(0, 0);
  lcd.print("Bet: ");
  lcd.print(betAmount);
  lcd.setCursor(0, 1);
  lcd.print("Total money: ");
  lcd.print(totalMoney);
  
  if (digitalRead(PinJoystick) == LOW){ // When clicked
  randNumber = 0 + randNumber;
  lcd.clear();
  digitalWrite(PinLeds[randNumber],LOW); // Turn of rand led from previous round
    for(int repeat = 0; repeat < 10; repeat++){ // Animation left to right
      	for(int i = 0; i < NumLeds; i ++){
        digitalWrite(PinLeds[i], HIGH);
        delay(50);
        digitalWrite(PinLeds[i],LOW);
      }
    }
  randNumber = random(5); // Chooses the led
  digitalWrite(PinLeds[randNumber],HIGH); // Turns on the led
  moneyEarnings = (randNumber - 2) * betAmount;
  if(moneyEarnings >= 0){
    lcd.print("You won: ");
    lcd.print(moneyEarnings);
  }
  else{
    lcd.print("You lost: ");
    lcd.print(moneyEarnings);
  }
  totalMoney = totalMoney + moneyEarnings;
  lcd.setCursor(0, 1);
  lcd.print("Total money: ");
  lcd.print(totalMoney);
  delay(3000);
  lcd.clear();
  }
}
