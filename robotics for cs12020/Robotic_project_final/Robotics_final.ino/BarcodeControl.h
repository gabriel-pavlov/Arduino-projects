#ifndef BarcodeControl_h
#define BarcodeControl_h

#include <Arduino.h>

class BarcodeControl {
  private:
    int readings[100];
    int capacity;
    int counter;


  public:

    BarcodeControl(int readingSize);
    bool isReading();
    bool isComplete();
    void reset();
    void putReading(int directionOfMovement);
    int getDirectionOfMovement();


};

#endif
