#include <ThingSpeak.h> 
#include <Wire.h> 
#include <Adafruit_Sensor.h> 
#include <Adafruit_BMP085_U.h> 
#include "DHT.h" 
#include <ESP8266WiFi.h> 
#include "ThingSpeak.h" 
 
#define DHTPIN D3 
#define DHTTYPE DHT11 
 
DHT dht(DHTPIN, DHTTYPE); 
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085); 
 
// WiFi credentials 
const char* ssid = "A70"; 
const char* password = "hppy6602"; 
 
// ThingSpeak settings 
const char* server = "api.thingspeak.com"; 
unsigned long myChannelNumber =2641342; 
const char* myWriteAPIKey = "DC8Z22LNQMPGZWGX"; 
 
// Sensor pins 
#define MQ7_PIN A0 
#define MQ3_PIN A0 // Change to another pin if using a multiplexer 
 
WiFiClient client;  
void setup() { 
  Serial.begin(115200); 
  WiFi.begin(ssid, password); 
   
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000); 
    Serial.println("Connecting to WiFi..."); 
  } 
   
  Serial.println("Connected to WiFi"); 
   
  ThingSpeak.begin(client); 
   
  dht.begin(); 
  if (!bmp.begin()) { 
    Serial.print("Could not find a valid BMP085 sensor, check wiring!"); 
    while (1); 
  } 
} 
 
void loop() { 
  float temperature = dht.readTemperature(); 
  float pressure; 
  bmp.getPressure(&pressure); 
   
  int mq7_value = analogRead(MQ7_PIN); 
  int mq3_value = analogRead(MQ3_PIN); 
   
  Serial.print("Temperature: "); 
  Serial.print(temperature); 
  Serial.print(" °C, Pressure: "); 
  Serial.print(pressure);  
  Serial.print(" Pa, MQ-7: "); 
  Serial.print(mq7_value); 
  Serial.print(", MQ-3: "); 
  Serial.println(mq3_value); 
   
  ThingSpeak.setField(1, temperature); 
  ThingSpeak.setField(2, pressure); 
  ThingSpeak.setField(3, mq7_value); 
  ThingSpeak.setField(4, mq3_value); 
  if (temperature > 26 || pressure > 101325) { // Example thresholds 
    Serial.println("ALERT! Abnormal conditions detected."); 
  } 
   
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 
   
  delay(2000); // Wait 20 seconds to update again 
}