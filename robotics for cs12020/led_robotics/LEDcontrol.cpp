#include "LEDcontrol.h"
#include "LED.h"

LEDcontrol::LEDcontrol(int pinRed, int pinYellow, int pinGreen) {
  red = LED(pinRed);
  yellow = LED(pinYellow);
  green = LED(pinGreen);
}

void LDRcontrol::turnIndicators(int directionOfMovement) {
  if (directionOfMovement > 0) {
    red.turnOn(); // indicates turning left
  } else if ( directionOfMovement < 0) {
    green.turnOn();  //indicates turning right
  }
}

void LDRcontrol::updateState() {
  red.updateState();
  yellow.updateState();
  green.updateState();
}
