#define BLYNK_TEMPLATE_ID "TMPL699bEqXgV"
#define BLYNK_TEMPLATE_NAME "Tilt Sensor"
#define BLYNK_AUTH_TOKEN "MZt4DAFMdg2ZCtxLAojf9hZ9AGYV1Rb3"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Ganti dengan kredensial Blynk Anda
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

const int tiltPin = 14;  // Tilt Switch SW-520D
const int ledPin = 26;   // LED
int tiltState = 0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Blynk.run();
  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);

  if (tiltState == HIGH) {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, "Stabil");
  } else {
    digitalWrite(ledPin, HIGH);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, "Miring");
  }

  delay(500);
}
