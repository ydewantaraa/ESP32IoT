#define BLYNK_TEMPLATE_ID "TMPL6KwPlP-1b"
#define BLYNK_TEMPLATE_NAME "Potentiometer"
#define BLYNK_AUTH_TOKEN "DljHVhw1IHVk2fzM22EArSx5PsE125mm"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "DljHVhw1IHVk2fzM22EArSx5PsE125mm";
char ssid[] = "";
char pass[] = "";

#define POT_PIN 34
#define LED_PIN 2

BlynkTimer timer;

void sendSensorData() {
  int potValue = analogRead(POT_PIN);
  int ledValue = map(potValue, 0, 4095, 0, 255);
  analogWrite(LED_PIN, ledValue);
  Blynk.virtualWrite(V1, potValue);
}

void setup() {
  // Inisialisasi serial, Blynk, dan pin LED
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED_PIN, OUTPUT);

  // Atur timer untuk mengirim data secara berkala
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}