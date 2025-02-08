#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigpin = 25;
const int echopin = 26;
long durasi;
int jarak;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  durasi = pulseIn(echopin, HIGH);
  jarak = durasi * 0.03408/2;
  Serial.print(jarak);
  Serial.println(" cm");
  lcd.setCursor(0, 0);
  lcd.print("Jarak :");
  lcd.setCursor(8, 0);
  lcd.print(jarak);
  lcd.setCursor(13, 0);
  lcd.print("cm");
  delay(500);
  lcd.clear();
}
