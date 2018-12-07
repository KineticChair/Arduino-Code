//Woon Jun Shen
//UM402 (433 MHz UART)
#include <SoftwareSerial.h>
#include <DHT.h>
SoftwareSerial mySerial(2, 3); //TX, RX
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHT22,15);
// gnd SET_A and SET_B for Normal Mode (Send and Receive)
float hum;
float temp;
char buff [10];
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();
}

void loop() {
hum = dht.readHumidity();
temp= dht.readTemperature();
hum += 0.5;
temp += 0.5;

 int realhum;
 int realtemp;
 realhum = int(hum);//converting a round up float humidity number to an integer humidity number 
 realtemp = int(temp);//converting a round up float temperature number to an integer temperature number

String transhum = String(realhum);//converting integer humidity value into String humidity value
String transtemp = String(realtemp);//converting integer temperature value into String temperature value. 
  //Code to read data and send it instead of reading from input data of Serial monitor 
  String input1 = transhum; // blah is whatever value you have as a string
  String input2 = transtemp;
  mySerial.println(input1);
  mySerial.println(input2);
  Serial.print("Humidity: ");
  Serial.print(transhum);
  Serial.print(" %, Temp: ");
  Serial.print(transtemp);
  Serial.print(" Celsius");

 
  if (mySerial.available() > 1) {//Read from UM402 and send to serial monitor
    String input1 = mySerial.readString();
    String input2 = mySerial.readString();
    Serial.println(input1);
    Serial.println(input2);    
  }
  delay(20);
}
  
 
