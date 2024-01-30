#include "LDRcontrol.h"
#include "LDR.h"

#include "LEDcontrol.h"
#include "LED.h"

#include "IRcontrol.h"
#include "IR.h"

#include "DrivetrainControl.h"

#include "Button.h"

int LDRreadings[3];

LDRcontrol ldrControl(A2, A1, A0, 25, 100, 13, 4);
LEDcontrol ledControl(13, 12, 7);
IRcontrol irControl(3, 2, 38000, 12, 4);
DrivetrainControl dControl (6, 5, 96, 96, 7, 4);
Button resetButton (4);
Button demoButton (2);

#define PBL 4 // defines pins for L and R push buttons
#define PBR 2

void demoMotors() {
  Serial.println("T.1-Motortest S");
  for (int i = 0; i < 10; i++) {
    dControl.moveForward();
    delay(1400);
    dControl.turnRight();
    delay(3600);
    dControl.turnLeft();
    delay(3600);
    dControl.moveBackward();
    delay(1400);
    dControl.halt();
    Serial.print("T.1-cycle ");
    Serial.println(i + 1);
    resetButton.waitUntilPressed();
  }
  Serial.println("T.1-Motortest F");
}

void demoLDR(String mode) {

  Serial.print("T.1-LDR S ");
  Serial.println(mode);

  int lAll[50];
  int mAll[50];
  int rAll[50];
  long lTotal = 0;
  long mTotal = 0;
  long rTotal = 0;
  long lMean = 0;
  long mMean = 0;
  long rMean = 0;
  long lSD = 0;
  long mSD = 0;
  long rSD = 0;

  Serial.println("T.1-LDR readings (10s)");
  for (int i = 0; i < 50; i++) {
    ldrControl.updateState(LDRreadings);
    lTotal += (long)LDRreadings[0];
    mTotal += (long)LDRreadings[1];
    rTotal += (long)LDRreadings[2];
    lAll[i] = LDRreadings[0];
    mAll[i] = LDRreadings[1];
    rAll[i] = LDRreadings[2];
    delay(200);
  }
  lMean = lTotal / 50; //mean for left
  mMean = mTotal / 50; //mean for middle
  rMean = rTotal / 50; //mean for right

  Serial.print("T.1-LDR left sensor readings mean ");
  Serial.println(lMean);
  Serial.print("T.1-LDR middle sensor readings mean ");
  Serial.println(mMean);
  Serial.print("T.1-LDR right sensor readings mean ");
  Serial.println(rMean);

  for (int i = 0; i < 50; i++) {
//    Serial.println(lAll[i]);
//    Serial.println(lMean);
//    Serial.println((lAll[i] - lMean));
//    Serial.println(lSD);
    lSD += (lAll[i] - lMean) * (lAll[i] - lMean);
    mSD += (mAll[i] - mMean) * (mAll[i] - mMean);
    rSD += (rAll[i] - rMean) * (rAll[i] - rMean);

  }


  Serial.print("T.1-LDR left sensor readings SD ");
  Serial.println(sqrt( (lSD) / 50));
  Serial.print("T.1-LDR middle sensor readings SD ");
  Serial.println(sqrt((mSD) / 50) );
  Serial.print("T.1-LDR right sensor readings SD ");
  Serial.println(sqrt( (rSD) / 50));
  Serial.println("T.1-LDR F");
  resetButton.waitUntilPressed();
}

void setupInternal() {
  Serial.println("setup-S");

  ldrControl.configure();
  irControl.configure();
  dControl.configure();



  ledControl.blinkIndicators();
  irControl.turnOFF();
  Serial.println("waitButton- waiting");
  while (true) {

    if (demoButton.isPressed()) {
      //demoMotors();
      demoLDR("dark");
      demoLDR("light");
      break;
    } else if  (resetButton.isPressed()) {
      break;
    }
  }
  irControl.turnON();
  ledControl.blinkIndicators();

  Serial.println("setup-F");
}

void setup() {

  Serial.begin(9600);
  setupInternal();
}

void loop() {
  Serial.println("loop-S");
  if (resetButton.isPressed()) {
    Serial.println("loop-reset");
    dControl.halt();
    setupInternal();
  }

  Serial.println("loop-update S");
  ldrControl.updateState(LDRreadings);
  irControl.updateState();
  Serial.println("loop-update F");

  bool blocked = irControl.isBlocked();


  if (blocked) {
    Serial.println("loop-blocked");
    dControl.halt();
    ledControl.blinkIndicators();

  } else {

    int pos = ldrControl.getDirectionOfMovement();
    ledControl.turnIndicators(pos);
    dControl.followDirection(pos);
    Serial.println("loop-direction = ");
    Serial.println(pos);

  }
  Serial.println("loop-F");
  delay(100);
}
