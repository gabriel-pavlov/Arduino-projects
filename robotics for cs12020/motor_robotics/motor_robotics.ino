#include <Servo.h>

//#define DEBUG

#define PBL 4 // defines pins for L and R push buttons
#define PBR 2

Servo LMotor;
Servo RMotor;

//current stop value

#define LSTOP 96
#define RSTOP 96

//sets the speed for each motor

int setSpeed(int lSpeed, int rSpeed) {

  LMotor.write(LSTOP + lSpeed);
  RMotor.write(RSTOP - rSpeed);

}

//find stop value for motors

void findStop(int lStop, int rStop) {

  for (int i = 75; i < 110; i++) {

    LMotor.write(i);
    RMotor.write(i);
    Serial.println(i);
    delay(3000);

  }

}

//debouncing algorithm

void waitKey(int pin, int lSpeed, int rSpeed) {
  while (digitalRead(pin) == HIGH) {}
  delay(20);
  while (digitalRead(pin) == LOW) {
      setSpeed(lSpeed, rSpeed);
  }
  delay(20);
  return;
}

void setup() {
  Serial.begin(9600);

  LMotor.attach(6);
  RMotor.attach(5);

  #ifdef DEBUG
      findStop(LSTOP, RSTOP);
  #endif

  setSpeed(0, 0);

  
   waitKey(PBL, 10, 10); //forwards
   delay(6000);
   setSpeed(0,0);

   //6.5 cm for 1 sec
   //14cm for 2 sec
   //21.5cm 
   //27.5cm
}

void loop() {

//  waitKey(PBL, 10, 10); //forwards
//  waitKey(PBL, -10, -10); //backwards
//  waitKey(PBL, 0, 0); //stop
//  waitKey(PBL, 20, 5); //turn right
//  waitKey(PBL, 5, 20); //turn left
//  waitKey(PBL, 10, -10); //rotate right
//  waitKey(PBL, -10, 10); // rotate left
//  waitKey(PBL, 0, 10); // pivot right
//  waitKey(PBL, 10, 0); //pivot left
  





}
