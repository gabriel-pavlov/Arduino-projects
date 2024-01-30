#ifndef IRcontrol_h
#define IRcontrol_h

#include "IR.h"
#include "LED.h"
#include "Button.h"
#include <Arduino.h>

class IRcontrol {
  private:
    IR obstacleDetector;
    LED configIndicator;
    void flashConfigIndicator();
    Button configButton;
   
  
  public:
    IRcontrol(int pinEmit,int pinRecieve, long frequency, int ledPin, int buttonPin);
    
    void updateState();
    bool isBlocked();
    void configure();
    void turnON();
    void turnOFF();


  
};

#endif
