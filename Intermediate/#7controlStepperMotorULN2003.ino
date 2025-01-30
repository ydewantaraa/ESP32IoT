#define BLYNK_TEMPLATE_ID "TMPL6JVYlCY0L"
#define BLYNK_TEMPLATE_NAME "Stepper Motor"
#define BLYNK_AUTH_TOKEN "0w-yS-JUmBBcCBBu2Ezq6Z7qfICzs_WA"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;  // Ganti dengan token dari Blynk
char ssid[] = "";         // Ganti dengan nama WiFi Anda
char pass[] = "";     // Ganti dengan password WiFi Anda

// Definisi pin untuk ULN2003 di ESP32
int motorPin1 = 18;
int motorPin2 = 19;
int motorPin3 = 21;
int motorPin4 = 22;
int delayTime = 5;
bool motorState = false; // Status motor

// Urutan langkah stepper motor (4-step sequence)
void stepMotor() {
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(delayTime);
  
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(delayTime);
  
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(delayTime);
  
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(delayTime);
}

// Fungsi untuk menangani tombol di Blynk
BLYNK_WRITE(V1) {
  motorState = param.asInt(); // Mengambil nilai dari Blynk button (0 atau 1)
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Konfigurasi pin sebagai output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  Blynk.run();  // Jalankan Blynk
  
  if (motorState) {
    stepMotor();
  }
}
