#include "DrivetrainControl.h"
#include <Arduino.h>
#include <Servo.h>

DrivetrainControl::DrivetrainControl(int pinLeft, int pinRight, int lStop, int rStop, int ledPin, int buttonPin) {
  lPin = pinLeft;
  rPin = pinRight;
  lStationary = lStop;
  rStationary = rStop;
  configIndicator = LED(ledPin);
  configButton = Button(buttonPin);

}

void DrivetrainControl::setSpeed(int lSpeed, int rSpeed) {

  lMotor.write(lStationary + lSpeed);
  rMotor.write(rStationary - rSpeed);

  Serial.print("DTspeed-"); 
  Serial.print(lSpeed); 
  Serial.print(" / ");
  Serial.println(rSpeed);

}

void DrivetrainControl::moveForward() {
  setSpeed(10, 10);
}  

void DrivetrainControl::moveBackward() {
  setSpeed(-10, -10);
}

void DrivetrainControl::turnLeft() {
  setSpeed(0, 10);
}

void DrivetrainControl::turnRight() {
  setSpeed(10, 0);
}

void DrivetrainControl::halt() {

  setSpeed(0, 0);

}

void DrivetrainControl::followDirection(int directionOfMovement) {

  switch (directionOfMovement) {
    case 10:  //going straight
      setSpeed(10, 10);
      break;
    case 100: // going right
      setSpeed(2, 15);
      break;
    case 1: //going left
      setSpeed(15, 2);
      break;
    case 111: //barcode read mode
      setSpeed(10, 10);
      break;
    default: //no track detected, failstate
      setSpeed(0, 0);
  }
}

void DrivetrainControl::configure() {
  Serial.println("DTconf-S");
  flashConfigIndicator();
  configIndicator.turnON();
  configButton.waitUntilPressed();
  configIndicator.turnOFF();
  Serial.println("DTconf-init motors");
  lMotor.attach(lPin);
  lMotor.write(lStationary);
  rMotor.attach(rPin);
  rMotor.write(rStationary);
  
  Serial.println("DTconf- forward");
  setSpeed(10, 10);
  delay(2000);
  Serial.println("DTconf-stop");
  setSpeed(0, 0);
  delay(1000);
  Serial.println("DTconf-left");
  setSpeed(10, 0);
  delay(2000);
  Serial.println("DTconf-right");
  setSpeed(0, 10);
  delay(2000);
  Serial.println("DTconf-stop");
  setSpeed(0, 0);
  flashConfigIndicator();
  Serial.println("DTconf-F");
}

void DrivetrainControl::flashConfigIndicator() {


  for (int i = 0; i < 3; i++) {
    configIndicator.turnON();
    delay(100);
    configIndicator.turnOFF();
    delay(100);
  }

}
