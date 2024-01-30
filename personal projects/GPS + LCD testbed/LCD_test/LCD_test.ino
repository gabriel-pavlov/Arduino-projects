#include <LiquidCrystal.h> // Include the required library

// Initialize the LCD object with the appropriate pins
const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;
const String BLANK = "                ";
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  lcdMessage( 0, 1, "hello world" );


}

void loop() {
  if (Serial.available()) { // check if there is any data available to be read
    String message = Serial.readString(); // read the incoming data as a string

    lcdMessage( 0, 1, message );

  }
  
}

void lcdMessage( int colPos, int rowPos, String message) {
  
  lcd.setCursor(colPos, rowPos);
  lcd.print(BLANK);
  lcd.setCursor(colPos, rowPos);
  lcd.print(message);
  
}
