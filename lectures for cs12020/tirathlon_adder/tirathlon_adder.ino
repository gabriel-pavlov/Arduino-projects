void setup() {
  // storage variables for athlete times, input should be akin to xxyyzz, where each set of two corresponds to a full time in hours, minutes and seconds
  int swimH = 0;
  int swimM = 0;
  int swimS = 0;
  int bikeH = 0;
  int bikeM = 0;
  int bikeS = 0;
  int runninH = 0;
  int runninM = 0;
  int runninS = 0;

  //recieve times from marshalls
  
  Serial.begin(9600);
  Serial.println("times should be input in hhmmss format");
  Serial.println("input the time for hours spent swimmming");
  while (!Serial.available()){
    ;
  }
  swimH = Serial.parseInt();
  Serial.println("input the time for minutes spent swimmming");
  while (!Serial.available()){
    ;
  }
  swimM = Serial.parseInt();
  Serial.println("input the time for seconds spent swimmming");
  while (!Serial.available()){
    ;
  }
  swimS = Serial.parseInt();

  Serial.println("input the time for hours spent bike");
  while (!Serial.available()){
    ;
  }
  bikeH = Serial.parseInt();
  Serial.println("input the time for minutes spent bike");
  while (!Serial.available()){
    ;
  }
  bikeM = Serial.parseInt();
  Serial.println("input the time for seconds spent bike");
  while (!Serial.available()){
    ;
  }
  bikeS = Serial.parseInt();
  
  Serial.println("input the time for hours spent running");
  while (!Serial.available()){
    ;
  }
  runninH = Serial.parseInt();
  Serial.println("input the time for minutes spent running");
  while (!Serial.available()){
    ;
  }
  runninM = Serial.parseInt();
  Serial.println("input the time for seconds spent running");
  while (!Serial.available()){
    ;
  }
  runninS = Serial.parseInt();

  //declare combined time storage variables

  int hour = 0;
  int minute = 0;
  int second = 0;
  // overflow variables
  int hCarry = 0;
  int mCarry = 0;

  //main arithemtic 

  second = swimS + bikeS + runninS;
  mCarry = second / 60;
  second = second % 60;

  minute = swimM + bikeM + runninM + mCarry;
  hCarry = minute / 60;
  minute = minute % 60;

  hour = swimH + bikeH + runninH + hCarry;
  
  //output combined total time

  Serial.print("Total time: ");
  Serial.print(hour);
  Serial.print("hr " );
  Serial.print(minute);
  Serial.print("min ");
  Serial.print(second);
  Serial.print("sec.");
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
