#include "BarcodeControl.h"

#include <Arduino.h>


BarcodeControl::BarcodeControl(int readingSize) {
  capacity = readingSize;
  counter = 0;

}
bool BarcodeControl::isReading() {
  return counter > 0;
}




bool BarcodeControl::isComplete() {
  return counter == (capacity - 1);
}
void BarcodeControl::reset() {
  counter = 0;
}
void BarcodeControl::putReading(int directionOfMovement) {
  if (!isComplete()) {
    readings[counter++] = directionOfMovement;
  }
}

//int BarcodeControl::getDirectionOfMovement() {
//  switch (directionOfMovement) {
//    case 10:  //going straight
//      setSpeed(10, 10);
//      break;
//    case 100: // going right
//      setSpeed(2, 15);
//      break;
//    case 1: //going left
//      setSpeed(15, 2);
//      break;
//    case 111: //barcode read mode
//      setSpeed(10, 10);
//      break;
//    default: //no track detected, failstate
//      setSpeed(0, 0);
//  }
//}
