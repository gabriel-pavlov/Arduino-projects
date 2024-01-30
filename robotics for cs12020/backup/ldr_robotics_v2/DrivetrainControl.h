#ifndef drivetrainControl_h
#define drivetrainControl_h

#include <Arduino.h>
#include "LED.h"
#include "Button.h"
#include <Servo.h>

class DrivetrainControl {
  private:
   Servo lMotor;
   Servo rMotor;
   int lStationary;
   int rStationary;
   int lPin;
   int rPin;
   void setSpeed(int lSpeed, int rSpeed);
   LED configIndicator;
   void flashConfigIndicator();
   Button configButton;
    
  
  public:

    DrivetrainControl(int pinLeft, int pinRight, int lStop, int rStop, int ledPin, int buttonPin);
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void halt();
    void followDirection(int directionOfMovement);
    void configure();


  
};

#endif
