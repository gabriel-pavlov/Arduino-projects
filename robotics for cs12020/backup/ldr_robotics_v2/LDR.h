#ifndef LDR_h
#define LDR_h

#include <Arduino.h>

class LDR {
  private:
    int ldrPin;
    int currentValue;
    int darkValue;
    int lightValue;
    int configureAttempts;
    int configureOffset;
    int configure();


  public:
    LDR();
    LDR(int pin, int attempts, int offset);

    int updateState();
    void configureDark();
    void configureLight();

    bool isOnBlack();
    bool isOnWhite();
    bool isOnGrey();




};

#endif
