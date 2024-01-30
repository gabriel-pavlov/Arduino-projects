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

const int RX = 0; // GPS TX connected to Arduino RX
const int TX = 1; // GPS RX connected to Arduino TX

void setup() {

  Serial.begin(9600); // Set serial baud rate to 9600 bps
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);

  lcd.begin(16, 2);

  lcdMessage( 0, 0, "hello world" );
  delay(2000);

}

void loop() {

  //  if (Serial.available()) {

  char c; //= Serial.read();

  //    if (c == '$') {
  // Look for the beginning of a new sentence
  String sentence = "";
  //      while (Serial.available() && sentence.length() < 80) {
  //        c = Serial.read();
  //        sentence += c;
  //        delay(10);
  //      }

  sentence = "$GPGGA,045104.000,3014.1985,N,09749.2873,W,1,09,1.2,211.6,M,-22.5,M,,0000*62\r\n";

  // Check for valid GPGGA sentence
  if (sentence.startsWith("$GPGGA")) {
    int commaCount = 0;
    float latitude = 0;
    float longitude = 0;

    for (int i = 0; i < sentence.length(); i++) {
      if (sentence[i] == ',') {
        commaCount++;

        switch (commaCount) {
          case 2:
            latitude = sentence.substring(i + 1, i + 10).toFloat();
            break;
          case 4:
            longitude = sentence.substring(i + 1, i + 10).toFloat();
            break;
        }
      }
    }

    Serial.print("Latitude: ");
    Serial.println(latitude, 5);
    Serial.print("Longitude: ");
    Serial.println(longitude, 5);

    String sLat = (String)(latitude);
    String sLon = (String)(longitude);

    //if (Serial.available()) { // check if there is any data available to be read
      //String message = Serial.readString(); // read the incoming data as a string

      lcdMessage( 0, 0, "Lat: " );
      lcdAppend( 6, 0, sLat );
      lcdMessage( 0, 1, "Lon: " );
      lcdAppend( 6, 1, sLon );
      
      

    //}

    delay(4000);


  }
  //    }
  // }
}

void lcdMessage( int colPos, int rowPos, String message) {

  lcd.setCursor(colPos, rowPos);
  lcd.print(BLANK);
  lcd.setCursor(colPos, rowPos);
  lcd.print(message);

}

void lcdAppend( int colPos, int rowPos, String message) {

  lcd.setCursor(colPos, rowPos);
  lcd.print(message);

}
