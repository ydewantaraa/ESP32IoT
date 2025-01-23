#define BLYNK_TEMPLATE_ID "TMPL6A7OrDdI7"
#define BLYNK_TEMPLATE_NAME "Control Servo Motor"
#define BLYNK_AUTH_TOKEN "OGqyw1XK1JoNe13fB3GrLegDz2fvlrze"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char auth[] = BLYNK_AUTH_TOKEN; // Blynk authentication token
char ssid[] = ""; // Your WiFi SSID
char pass[] = ""; // Your WiFi password

Servo servo1;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo1.attach(2); // Attach servo 1 to GPIO 2
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0) // Slider Widget for Servo 1 on V0
{
  int position = param.asInt(); // Get value from slider
  servo1.write(position); // Set servo 1 position
  Blynk.virtualWrite(V1, position);
}
