#define BLYNK_TEMPLATE_ID "TMPL67c7eShov"
#define BLYNK_TEMPLATE_NAME "Seven Segment Display"
#define BLYNK_AUTH_TOKEN "dm0zYax7IdDIIaHYsMxM0N88ER8VqrNp"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
}

BLYNK_WRITE(V0) {
    int buttonState = param.asInt();
    // display number 1
    digitalWrite(4, buttonState);
    digitalWrite(15, buttonState);
    delay(1000);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  // display number 2
  digitalWrite(2, buttonState);
  digitalWrite(4, buttonState);
  digitalWrite(5, buttonState);
  digitalWrite(18, buttonState);
  digitalWrite(21, buttonState);
  delay(1000);
}

BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  // display number 3
  digitalWrite(2, buttonState);
  digitalWrite(4, buttonState);
  digitalWrite(15, buttonState);
  digitalWrite(5, buttonState);
  digitalWrite(21, buttonState);
  delay(1000);
}

void loop()
{
  Blynk.run();
}
