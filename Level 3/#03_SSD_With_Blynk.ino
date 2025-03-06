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
  // display number 0
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(E, buttonState);
  digitalWrite(F, buttonState);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  // display number 1
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
}

BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  // display number 2
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(E, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  // display number 3
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V4) {
  int buttonState = param.asInt();
  // display number 4
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(F, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V5) {
  int buttonState = param.asInt();
  // display number 5
  digitalWrite(A, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(F, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V6) {
  int buttonState = param.asInt();
  // display number 6
  digitalWrite(A, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(E, buttonState);
  digitalWrite(F, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V7) {
  int buttonState = param.asInt();
  // display number 7
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
}

BLYNK_WRITE(V8) {
  int buttonState = param.asInt();
  // display number 8
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(E, buttonState);
  digitalWrite(F, buttonState);
  digitalWrite(G, buttonState);
}

BLYNK_WRITE(V9) {
  int buttonState = param.asInt();
  // display number 9
  digitalWrite(A, buttonState);
  digitalWrite(B, buttonState);
  digitalWrite(C, buttonState);
  digitalWrite(D, buttonState);
  digitalWrite(F, buttonState);
  digitalWrite(G, buttonState);
}

void loop()
{
  Blynk.run();
}
