void setup() {
   // storage variables for athlete times, input should be akin to xxyyzz, where each set of two corresponds to a full time in hours, minutes and seconds
  const int SWIM_S = 0;
  const int BIKE_S = 1;
  const int RUNNING_S = 2;
  const int TOTAL_S = 3;
  String names[] = {"Swim", "Bike", "Run", "Total"};
  long storage[] = { 0, 0, 0, 0};

  //recieve times from marshalls
  
  Serial.begin(9600);
  
  Serial.println("input the time for hours spent swimmming");
  while (!Serial.available()){
    ;
  }
  storage[SWIM_S] = (60 * 60 * Serial.parseInt());
  Serial.println("input the time for minutes spent swimmming");
  while (!Serial.available()){
    ;
  }
  storage[SWIM_S] += (60 * Serial.parseInt());
  Serial.println("input the time for seconds spent swimmming");
  while (!Serial.available()){
    ;
  }
  storage[SWIM_S] += Serial.parseInt();
  
  Serial.println("input the time for hours spent bike");
  while (!Serial.available()){
    ;
  }
  
  
  storage[BIKE_S] = (60 * 60 * Serial.parseInt());
  Serial.println("input the time for minutes spent bike");
  while (!Serial.available()){
    ;
  }
  storage[BIKE_S] += (60 * Serial.parseInt());
  Serial.println("input the time for seconds spent bike");
  while (!Serial.available()){
    ;
  }
  storage[BIKE_S] += Serial.parseInt();
  
  Serial.println("input the time for hours spent running");
  while (!Serial.available()){
    ;
  }
  storage[RUNNING_S] = (60 * 60 * Serial.parseInt());
  Serial.println("input the time for minutes spent running");
  while (!Serial.available()){
    ;
  }
  storage[RUNNING_S] += (60 * Serial.parseInt());
  Serial.println("input the time for seconds spent running");
  while (!Serial.available()){
    ;
  }
  storage[RUNNING_S] += Serial.parseInt();
  

  storage[TOTAL_S] = storage[SWIM_S] + storage[BIKE_S] + storage[RUNNING_S];

  //declare combined time storage variables

  long hour = 0;
  long minute = 0;
  long second = 0;

  //main arithemtic 

  for(int i = 0; i < 4; i++){

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
