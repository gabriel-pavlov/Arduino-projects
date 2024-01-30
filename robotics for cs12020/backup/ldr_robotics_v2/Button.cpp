#include "Button.h"

#include <Arduino.h>

Button::Button() {

}

Button::Button(int pin) {
  buttonPin   = pin;

}

void Button::waitUntilPressed() {
  Serial.println("waitButton- waiting");
  while (digitalRead(buttonPin) == HIGH) {}
  delay(20);
  while (digitalRead(buttonPin) == LOW) {}
  delay(20);
  
}

bool Button::isPressed() { 
  return (digitalRead(buttonPin) == LOW); 
}
