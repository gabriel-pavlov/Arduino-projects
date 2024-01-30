#include "LEDcontrol.h"
#include "LED.h"

LEDcontrol::LEDcontrol(int pinRed, int pinYellow, int pinGreen) {
  red = LED(pinRed);
  yellow = LED(pinYellow);
  green = LED(pinGreen);
}

void LEDcontrol::turnIndicators(int directionOfMovement) {
  switch (directionOfMovement) {
    case 10:  //going straight
      red.turnOFF();
      yellow.turnOFF();
      green.turnOFF();
      break;
    case 100: // going right
      red.turnON();
      yellow.turnOFF();
      green.turnOFF();
      break;
    case 1: //going left
      red.turnOFF();
      yellow.turnOFF();
      green.turnON();
      break;
    case 111: //barcode read mode
      red.turnOFF();
      yellow.turnON();
      green.turnOFF();
      break;
    default: //no track detected, failstate
      red.turnON();
      yellow.turnON();
      green.turnON();


  }
}

void LEDcontrol::blinkIndicators() {
  for (int i = 0; i < 3; i++) {
      red.turnON();
      yellow.turnON();
      green.turnON();
      delay(100);
      red.turnOFF();
      yellow.turnOFF();
      green.turnOFF();
  }
}
