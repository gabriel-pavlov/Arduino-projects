#include "LED.h"

#include <Arduino.h>

LED::LED() {

}

LED::LED(int pin) {
  ledPin   = pin;
  ledState = false;
  pinMode(ledPin, OUTPUT);
}

void LED::turnON() {
  ledState = true;
  digitalWrite(ledPin, HIGH);
}

void LED::turnOFF() {
  ledState = false;
  digitalWrite(ledPin, LOW);
}

bool LED::isON() {
  return ledState;
}
