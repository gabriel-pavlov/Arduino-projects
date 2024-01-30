#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED {
  private:
    int ledPin;
    bool ledState;

  public:
    LED();
    LED(int pin);
    void turnON();
    void turnOFF();
    bool isON();
};

#endif
