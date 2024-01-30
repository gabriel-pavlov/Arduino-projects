#include <stdio.h>

#define DEBUG

String names[] = {"Swimming" , "Biking" , "Running" , "Total"};
String increments[] = {"hours", "minutes", "seconds "};
long storage[] = { 0, 0, 0, 0};
int powers[] = {3600, 60, 1};
long bestAthlete[]= {0, 2147483647};


int timeCalc(int type) {

  // i represents index in storage. loop in reverse because i can be repurposed as 60 to power of i for hours and minutes

  for ( int i = 0; i < 3; i++) {
    Serial.print("input the time for ");
    Serial.print(names[type]);
    Serial.print(" spent ");
    Serial.println(increments[i]);
    while (!Serial.available()) {
      ;
    }

    //for i bigger than 0, use 60^i to convert to seconds
    storage[type] += powers[i] * Serial.parseInt();
    if (storage[0] < 0) {
      #ifdef DEBUG 
       Serial.println("loop break successfull");
      #endif
      break;
    }


  }

  return 0;
}


void setup() {

  int counter = 1;
  bool posTime = true;
  Serial.begin(9600);

  long hour = 0;
  long minute = 0;
  long second = 0;

  while (posTime == true) {

    //loop through all categories, indexes 1 to 3 (index 0 excluded as it is total)
    for ( int i = 0; i < 3; i++) {

      timeCalc(i);
      if (storage[0] < 0) {
        posTime = false;
        #ifdef DEBUG
          Serial.println("loop break successfull");
        #endif
        break;
      }

    }

    // sum up to get total from all categories collected by time calc function
    storage[3] = storage[0] + storage[1] + storage[2];
    #ifdef DEBUG
     Serial.println("summation done");
     Serial.println(storage[3]);
    #endif
    

    //conversion back to hours, minutes and seconds and output

    for (int i = 0; i < 4; i++) {
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

    Serial.println("");
    
    #ifdef DEBUG
      Serial.println("loop complete");
    #endif
    

    if (storage[3] < bestAthlete[1] && !(storage[3] < 0)) {

      #ifdef DEBUG
          Serial.println("");
      #endif
      
      bestAthlete[1] = storage[3];
      bestAthlete[0] = counter; 
      #ifdef DEBUG
          Serial.println("updating");
          Serial.println(storage[3]);
          Serial.println(bestAthlete[1]);
      #endif
      
    }
    #ifdef DEBUG 
      Serial.println("best athlete stored");
      Serial.println(bestAthlete[0]);
      Serial.println(bestAthlete[1]);
      Serial.println(counter);
      Serial.println(storage[3]);
    #endif

    for (int i = 0; i < 4; i++){
      storage[i] = 0;  
    }
    counter++;

    #ifdef DEBUG
      Serial.println("data erased and counter incremented");
      Serial.println(storage[3]);
      Serial.println(counter);
    #endif
    
  }

  Serial.println(bestAthlete[1]);
  Serial.println(storage[3]);

  hour = bestAthlete[1] / 3600;
  minute = (bestAthlete[1] - (hour * 3600)) / 60;
  second = bestAthlete[1] - (hour * 3600) - (minute * 60);

  Serial.println("==========");
  Serial.print("The fastest athlete was no. ");
  Serial.print(bestAthlete[0]);

  Serial.print(" with a total time of ");
  Serial.print(hour);
  Serial.print("hr ");
  Serial.print(minute);
  Serial.print("min ");
  Serial.print(second);
  Serial.println("sec.");
  Serial.println("==========");



}

void loop() {


}
