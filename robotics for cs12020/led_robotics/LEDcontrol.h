#ifndef LEDcontrol_h
#define LEDcontrol_h

#include "LED.h"
#include <Arduino.h>

class LDRcontrol {
  private:
    LED red;
    LED yellow;
    LED green;
    
  
  public:
    LEDcontrol(int pinRed, int pinYellow, int pinGreen);
    void turnIndicators(int directionOfMovement);
    void updateState();

  
};

#endif
