#define BLYNK_TEMPLATE_ID "TMPL6nWWjZeah"
#define BLYNK_TEMPLATE_NAME "Led Blink"
#define BLYNK_AUTH_TOKEN "P8GicZw5gH6MlyTwCRMrsRjjobcxOnov"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Nama_WiFi";
char pass[] = "Password_WiFi";

const int ledPin = 2;

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    pinMode(ledPin, OUTPUT);
}

BLYNK_WRITE(V0)
{
    int buttonState = param.asInt();
    digitalWrite(ledPin, buttonState);
}

void loop()
{
    Blynk.run();
}
