#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define POT_PIN 36 // Pin ADC untuk potensiometer

BlynkTimer timer;

void sendSensorData() {
  int potValue = analogRead(POT_PIN); // Membaca data analog
  Blynk.virtualWrite(V1, potValue);  // Mengirim data ke Blynk
}

void setup() {
  // Inisialisasi serial dan Blynk
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Atur timer untuk mengirim data secara berkala
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
