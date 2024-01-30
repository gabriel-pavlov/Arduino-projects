#ifndef LDRcontrol_h
#define LDRcontrol_h

#include "LDR.h"
#include "LED.h"
#include "Button.h"
#include <Arduino.h>

class LDRcontrol {
  private:
    LDR left;
    LDR middle;
    LDR right;
    LED configIndicator;
    void flashConfigIndicator();
    Button configButton;
    
  
  public:
    LDRcontrol(int pinLeft, int pinMiddle, int pinRight, int attempts, int offset, int ledPin, int buttonPin);
    int getDirectionOfMovement();
    void updateState(int (& readings) [3]);
    void configure();

    


  
};

#endif
