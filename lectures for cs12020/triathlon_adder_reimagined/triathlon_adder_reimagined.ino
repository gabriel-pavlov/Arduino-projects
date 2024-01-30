String names[] = {"Total", "Running" , "Biking" , "Swimming" };
String increments[] = {"seconds ", "minutes", "hours"};
long storage[] = { 0, 0, 0, 0};
int powers[] = {1, 60, 3600};


int timeCalc(int type) {

  // i represents index in storage. loop in reverse because i can be repurposed as 60 to power of i for hours and minutes
 
  for ( int i = 3; i > 0; i--) {
    Serial.print("input the time for ");
    Serial.print(names[type]);
    Serial.print(" spent ");
    Serial.println(increments[i-1]);
    while (!Serial.available()) {
      ;
    }
    
      //for i bigger than 0, use 60^i to convert to seconds
      storage[type] += powers[i-1] * Serial.parseInt();

  }

  return 0;
}

void setup() {
  //initialise serial port to enable communication
  Serial.begin(9600);

  //loop through all categories, indexes 1 to 3 (index 0 excluded as it is total)
  for ( int i = 3; i > 0; i--) {
 
    timeCalc(i);

  }

  // sum up to get total from all categories collected by time calc function
  storage[0] = storage[1] + storage[2] + storage[3];

  long hour = 0;
  long minute = 0;
  long second = 0;

  //conversion back to hours, minutes and seconds and output

  for (int i = 3; i >= 0; i--) {
    hour = storage[i] / 3600;
    minute = (storage[i] - (hour * 3600)) / 60;
    second = storage[i] - (hour * 3600) - (minute * 60);

    Serial.print(names[i]); 
    Serial.print(" time: ");  
    Serial.print(hour); 
    Serial.print("hr "); 
    Serial.print(minute); 
    Serial.print("min ");
    Serial.print(second); 
    Serial.println("sec.");

  }

}

  void loop() {
    // put your main code here, to run repeatedly:

  }
