#include "IRcontrol.h"
#include "IR.h"


IRcontrol::IRcontrol(int pinEmit, int pinRecieve, long frequency, int ledPin, int buttonPin) {
  obstacleDetector = IR(pinEmit, pinRecieve, frequency);
  configIndicator = LED(ledPin);
  configButton = Button(buttonPin);

}

void IRcontrol::updateState() {
  obstacleDetector.updateState();
}

bool IRcontrol::isBlocked() {
  return obstacleDetector.isRecieving();

}

void IRcontrol::configure() {
  Serial.println("IRCconf-S");
  
  flashConfigIndicator();
  configIndicator.turnON();
  configButton.waitUntilPressed();
  configIndicator.turnOFF();
  obstacleDetector.configure();
  Serial.println("IRCconf-EMON");

  for (int i = 0; i < 3; i++) {
    Serial.print("IRCconf-test ");
    Serial.println(i);
    while (!obstacleDetector.isRecieving() ) {
      obstacleDetector.updateState();
      delay(100);
    }
    configIndicator.turnON();
    while (obstacleDetector.isRecieving() ) {
      obstacleDetector.updateState();
      delay(100);
    }
    configIndicator.turnOFF();
  }

  flashConfigIndicator();
  Serial.println("IRCconf-F");
}

void IRcontrol::flashConfigIndicator() {

  for (int i = 0; i < 3; i++) {
    configIndicator.turnON();
    delay(100);
    configIndicator.turnOFF();
    delay(100);
  }
}

void IRcontrol::turnON() {
  obstacleDetector.unlock();
}

void IRcontrol::turnOFF() {
  obstacleDetector.lock();
}
