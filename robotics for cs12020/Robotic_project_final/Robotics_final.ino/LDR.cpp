#include "LDR.h"

LDR::LDR() {


}

LDR::LDR(int pin, int attempts, int offset) {
  ldrPin = pin;
  configureAttempts = attempts;
  configureOffset = offset;
  pinMode(ldrPin, INPUT);

}

int LDR::updateState() {
  currentValue = analogRead(ldrPin);
//  Serial.print("LDR read ");
//  Serial.println(currentValue);
  return currentValue;
}

int LDR::configure() {

  int val;

  for (int i = 0; i < configureAttempts; i++) {
    val += analogRead(ldrPin);
//    Serial.print("LDR read ");
//    Serial.println(val);
    delay(10);
  }
  Serial.print("LDR read ");
  Serial.println(val);
  val /= configureAttempts;
  Serial.print("LDRconf-mean ");
  Serial.print(val);
  Serial.print(" pin ");
  Serial.println(ldrPin);
  return val;
}



void LDR::configureDark() {
  darkValue = configure();
}

void LDR::configureLight() {
  lightValue = configure();
}

bool LDR::isOnBlack() {
  return currentValue < (darkValue + configureOffset);
}
bool LDR::isOnWhite() {
  return currentValue > (lightValue - configureOffset);
}
bool LDR::isOnGrey() {
  return !isOnBlack() && !isOnWhite();
}
