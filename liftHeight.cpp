// Do not remove the include below
#include "liftHeight.h"
#include <LiquidCrystal.h>
#include <StringPotentiometer.h>

LiquidCrystal lcd(12,11,5,4,3,2);

StringPotentiometer liftHeight(A0, 10.0, 2.4, false);
//StringPotentiometer liftInvert(A0, 10.0, 2.4, true);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
}

void loop(){

  float liftMeasure = liftHeight.getMeasure();
  String liftMoves = liftHeight.setDirection(12.5);
  bool liftFinished = liftHeight.isFinished(liftMoves, 12.5);
  //float liftInvMeasure = liftInvert.getMeasure();

  lcd.setCursor(0,0);
  lcd.print(liftMoves);
  lcd.print(" ");
  lcd.print(liftFinished);
  lcd.print(" ");
  //lcd.print(liftInvMeasure);
  lcd.setCursor(0,1);
  lcd.print(liftMeasure);

  delay(100);
}


