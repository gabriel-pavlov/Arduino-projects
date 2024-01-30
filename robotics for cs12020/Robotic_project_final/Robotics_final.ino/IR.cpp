#include "IR.h"

#include <Arduino.h>

IR::IR() {

}

IR::IR(int emitPin, int recievePin, long frequency) {
  irEmitterPin   = emitPin;
  irRecieverPin = recievePin;
  irState = false;
  freq = frequency;
  locked = true;


}

void IR::updateState() {
  if (digitalRead(irRecieverPin) == LOW) {
    irState = true;
  } else {
    irState = false;
  }

}

bool IR::isRecieving() {
  return irState;
}

void IR::configure() {
  pinMode(irEmitterPin, OUTPUT);
  pinMode(irRecieverPin, INPUT);

  tone(irEmitterPin, freq); // send pulses to pin at frequency hz
  locked = false;
}

void IR::lock() {
  if (!locked) {
    noTone(irEmitterPin);
    Serial.println("IRlock-Y");
    locked = true;
  }
}

void IR::unlock() {
  if (locked) {
    tone(irEmitterPin, freq);
    Serial.println("IRlock-N");
    locked = false;
  }
}

bool IR::isLocked() {
  return locked;
}
