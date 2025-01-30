#define BLYNK_TEMPLATE_ID "TMPL6mOpl3W_b"
#define BLYNK_TEMPLATE_NAME "LCD"
#define BLYNK_AUTH_TOKEN "_Qr2iJGVdtqvCMp1us0o7rCZSV-jxa8k"

#include <WiFi.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>

// Konfigurasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V1) {
  String data = param.asStr();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(data);
}

void setup() {
  lcd.init();
  lcd.backlight();
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
}
