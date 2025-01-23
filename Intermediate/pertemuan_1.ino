#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define LED_PIN 2 // Pin LED

BLYNK_WRITE(V0) {
  int buttonState = param.asInt(); // Membaca status tombol dari Blynk
  digitalWrite(LED_PIN, buttonState); // Mengatur LED sesuai tombol
}

void setup() {
  // Inisialisasi serial dan Blynk
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Atur pin LED sebagai output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  Blynk.run();
}
