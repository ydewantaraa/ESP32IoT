#define BLYNK_TEMPLATE_ID "TMPL6v3Kg-JLl"
#define BLYNK_TEMPLATE_NAME "Palang Pintu"
#define BLYNK_AUTH_TOKEN "EJSdldlnxGCEyJhbhjtIGx-U8W_HHumm"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

Servo myservo;

#define TRIG_PIN 14
#define ECHO_PIN 12
#define SERVO_PIN 22

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";  // Ganti dengan SSID WiFi
char pass[] = "";  // Ganti dengan password WiFi

bool notified = false; // Untuk menghindari spam notifikasi

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO_PIN);
}

void loop() {
  Blynk.run();

  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    myservo.write(0);
    delay(500);

    if (!notified) {
      Blynk.logEvent("terbuka", "Palang pintu terbuka! Kendaraan terdeteksi.");
      notified = true;
    }
  } else {
    myservo.write(90);
    notified = false;
  }

  delay(1000);
}
