

void setup() {
  Serial.begin(9600);

  pinMode(3,OUTPUT); //IR led pin
  pinMode(2, INPUT); //IR reciever pin

  tone(3, 38000); // send pulses to pin 3 at 38Khz


  
}



void loop() {


  if (digitalRead(2) == LOW) {
    Serial.println("obstacle found");
  } else {
    Serial.println("path is clear");
  }
  delay(500);


Serial.println(analogRead(2));

}
