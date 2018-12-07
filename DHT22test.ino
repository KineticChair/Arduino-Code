#include <DHT.h>
#include <SoftwareSerial.h>
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHT22);
void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop() {
 //we delay a little bit for next read
  delay(3000);
  //use the functions which are supplied by library.
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  
  
  delay(3000);
  // since both of these calls trigger sensor communication, wait in between them!
  
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
   Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp: ");
    Serial.print(t);
    Serial.println(" Celsius");
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
