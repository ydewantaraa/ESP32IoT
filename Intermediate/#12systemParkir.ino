#define BLYNK_TEMPLATE_ID "TMPL6P_UPgtvI"
#define BLYNK_TEMPLATE_NAME "Parkir"
#define BLYNK_AUTH_TOKEN "JcfhzBJ4kIx01GZTzcrsd84PY7uH1YQ5"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define RED_LED_PIN 27
#define GREEN_LED_PIN 14

BlynkTimer timer;

void cekjarak() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2;
  
  Blynk.virtualWrite(V0, distance);

  if (distance <= 50.0) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    Blynk.virtualWrite(V1, "Mobil sudah dekat dengan dinding\n");
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    Blynk.virtualWrite(V1, "Mobil masih bisa mundur\n");
  }
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, "Wokwi-GUEST", "");
  
  timer.setInterval(1000L, cekjarak);
}

void loop() {
  Blynk.run();
  timer.run();
}
