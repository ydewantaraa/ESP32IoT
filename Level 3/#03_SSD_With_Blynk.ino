#define BLYNK_TEMPLATE_ID "TMPL67c7eShov"
#define BLYNK_TEMPLATE_NAME "Seven Segment Display"
#define BLYNK_AUTH_TOKEN "dm0zYax7IdDIIaHYsMxM0N88ER8VqrNp"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

const int A = 2;
const int B = 4;
const int C = 15;
const int D = 5;
const int E = 18;
const int F = 19;
const int G = 21;

void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

BLYNK_WRITE(V0) {
    int buttonState = param.asInt();
    // display number 1
    digitalWrite(B, buttonState);
    digitalWrite(C, buttonState);
    delay(1000);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  // display number 2
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(E, buttonState);
  digitalWrite(G, buttonState);
  delay(1000);
}

BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  // display number 3
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(G, buttonState);
  delay(1000);
}

void loop()
{
  Blynk.run();
}
