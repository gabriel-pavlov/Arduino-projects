#ifndef IR_h
#define IR_h

#include <Arduino.h>

class IR {
  private:
    int irEmitterPin;
    int irRecieverPin;
    bool irState;
    long freq;
    bool locked;

  public:
    IR();
    IR(int emitPin, int recievePin, long frequency);
    void updateState();
    bool isRecieving();
    void configure();
    
    void lock();
    void unlock();
    bool isLocked();
};

#endif
