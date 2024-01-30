#include "LDRcontrol.h"
#include "LDR.h"



LDRcontrol::LDRcontrol(int pinLeft, int pinMiddle, int pinRight, int attempts, int offset, int ledPin, int buttonPin) {
  left = LDR(pinLeft, attempts, offset);
  middle = LDR(pinMiddle, attempts, offset);
  right = LDR(pinRight, attempts, offset);
  configIndicator = LED(ledPin);
  configButton = Button(buttonPin);
}

int LDRcontrol::getDirectionOfMovement() {
  if (left.isOnWhite() && middle.isOnBlack() && right.isOnWhite()) {
    return 10; //going straight
  } else if ( left.isOnBlack() && right.isOnWhite()) {
    return 100; // going right
  } else if (left.isOnWhite() && right.isOnBlack()) {
    return 1; //going left
  } else if (left.isOnBlack() && middle.isOnBlack() && right.isOnBlack()) {
    return 111; //barcode read mode
  } else {
    return 0; //no track detected, failstate
  }
}

void LDRcontrol::updateState(int (& readings) [3]) {
  readings[0] = left.updateState();
  readings[1] = middle.updateState();
  readings[2] = right.updateState();
}



void LDRcontrol::configure() {
  Serial.println("LDRCconf-S");
  //configuring dark values
  Serial.println("LDRCconf-dark");
  flashConfigIndicator();
  configIndicator.turnON();
  configButton.waitUntilPressed();
  configIndicator.turnOFF();
  left.configureDark();
  middle.configureDark();
  right.configureDark();

  // configuring light values
  Serial.println("LDRCconf-light");
  flashConfigIndicator();
  configIndicator.turnON();
  configButton.waitUntilPressed();
  configIndicator.turnOFF();
  left.configureLight();
  middle.configureLight();
  right.configureLight();

  flashConfigIndicator();
  Serial.println("LDRCconf-F");
}

void LDRcontrol::flashConfigIndicator() {

  for (int i = 0; i < 3; i++) {
    configIndicator.turnON();
    delay(100);
    configIndicator.turnOFF();
    delay(100);
  }

}
