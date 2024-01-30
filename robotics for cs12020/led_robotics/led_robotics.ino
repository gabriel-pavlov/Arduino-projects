

#define GREEN 7 // defines pins for diffrent leds
#define YELLOW 12
#define RED 13

#define PBL 4 // defines pins for L and R push buttons
#define PBR 2

//sets leds at the beginning
void setLEDs(int green_state, int yellow_state, int red_state) {
  if (green_state == 0) {
    digitalWrite(GREEN, LOW);
  } else {
    digitalWrite(GREEN, HIGH);
  }
  if (yellow_state == 0) {
    digitalWrite(YELLOW, LOW);
  } else {
    digitalWrite(YELLOW, HIGH);
  }
  if (red_state == 0) {
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(RED, HIGH);
  }

}

void setup() {
  
  pinMode(7, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

    while (digitalRead(PBL) == HIGH) {}
    while (digitalRead(PBL) == LOW) {
      setLEDs(1,0,1);
    }

   while (digitalRead(PBR) == HIGH) {}
    while (digitalRead(PBR) == LOW) {
      setLEDs(0,0,0);
    }


}

void loop() {

   while (digitalRead(PBL) == HIGH) {}
    while (digitalRead(PBL) == LOW) {
      setLEDs(1,0,1);
    }

   while (digitalRead(PBR) == HIGH) {}
    while (digitalRead(PBR) == LOW) {
      setLEDs(0,0,0);
    }

}
