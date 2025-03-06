#include <ESP32Servo.h>

Servo myservo;

#define TRIG_PIN 14   // Pin Trigger sensor ultrasonik
#define ECHO_PIN 12   // Pin Echo sensor ultrasonik
#define SERVO_PIN 22  // Pin yang terhubung ke servo

// Objek ServoESP32

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO_PIN);
}

void loop() {
  long duration, distance;

  // Kirim sinyal ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca waktu pantulan ultrasonik
  duration = pulseIn(ECHO_PIN, HIGH);

  // Hitung jarak dalam cm
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Jika jarak kurang dari 300 cm, gerakkan servo 90 derajat
  if (distance < 300) {
    myservo.write(90);
    delay(500);  // Tunggu sebentar untuk memberikan waktu servo bergerak
  } else {
    myservo.write(0);  // Kembalikan servo ke posisi awal jika tidak ada objek dalam jarak
  }

  delay(1000);  // Tunggu sejenak sebelum mengukur lagi
}
