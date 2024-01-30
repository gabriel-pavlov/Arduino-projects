#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
  private:
    int buttonPin;

  public:
    Button();
    Button(int pin);
    void waitUntilPressed();
    bool isPressed();

};

#endif
