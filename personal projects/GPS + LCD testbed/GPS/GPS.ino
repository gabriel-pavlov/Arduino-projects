#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RX_PIN 3
#define TX_PIN 2
#define LED_PIN 7
#define GPS_BAUD 9600
#define WAYPOINT_THRESHOLD 5

TinyGPSPlus gps;

SoftwareSerial ss(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  ss.begin(GPS_BAUD);
  pinMode(LED_PIN, OUTPUT);

  Serial.Println("Waypoint tracker");

}

void loop() {
  double targetLat = 52.417114567377936;
  double targetLon = -4.062179665880415;

  while(ss.available() > 0) {
    gps.encode(ss.read());

      double dist = 0;
     if (gps.location.isValid()){
        dist = distance(targetLat, targetLon, gps.location.lat(), gps.location.lng());
        Serial.print("distance to target is");
        Serial.println(dist);
      }

      if (dist < WAYPOINT_THRESHOLD)
      digitalWrite(LED_PIN, HIGH);
       
  }
  
}

double distance(double lat1, double lon1, double lat2, double lon2)
{
  // Conversion factor from degrees to radians (pi/180)
  const double toRadian = 0.01745329251;

  // First coordinate (Radians)
  double lat1_r = lat1 * toRadian;
  double lon1_r = lon1 * toRadian;

  // Second coordinate (Radians)
  double lat2_r = lat2 * toRadian;  
  double lon2_r = lon2 * toRadian;

  // Delta coordinates 
  double deltaLat_r = (lat2 - lat1) * toRadian;
  double deltaLon_r = (lon2 - lon1) * toRadian;

  // Distance
  double a = sin(deltaLat_r/2)*sin(deltaLat_r/2) + cos(lat1_r) * cos(lat2_r) * sin(deltaLon_r/2) * sin(deltaLon_r/2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  double distance = 6371 * c * 1000;

  return distance;
}
