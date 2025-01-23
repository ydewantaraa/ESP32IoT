#define BLYNK_TEMPLATE_ID "TMPL6B5Xt2ldr"
#define BLYNK_TEMPLATE_NAME "Notifikasi Suhu dan Kelembapan"
#define BLYNK_AUTH_TOKEN "ZHG2Ls0Pyc5Ad6VpXcxXUgWY1PvOdLqC"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
 

#include <DHT.h>

char auth[] = "ZHG2Ls0Pyc5Ad6VpXcxXUgWY1PvOdLqC";

char ssid[] = "nama-wifi";  // type your wifi name
char pass[] = "password-wifi";  // type your wifi password

#define DHTPIN 4          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void setup(){
   Serial.begin(115200);
  
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
  Serial.print("Suhu : ");
  Serial.print(t);
  Serial.print("|| Kelembapan : ");
  Serial.println(h);


  if(t > 2){
    Blynk.logEvent("suhu","Suhu Normal");
  }

  if(h > 20){
    Blynk.logEvent("kelembapan","Kelembapan Normal");
  }
}