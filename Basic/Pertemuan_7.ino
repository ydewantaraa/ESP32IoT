#define BLYNK_TEMPLATE_ID "TMPL6BhLnzYTX"
#define BLYNK_TEMPLATE_NAME "Pertemuan 3 Suhu dan Kelembapan"
#define BLYNK_AUTH_TOKEN "nbh5cOrGJNq5ijUZ61AlE4LsGYzwItW7"

// Include necessary libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

// LCD I2C configuration
LiquidCrystal_I2C lcd(0x27, 16, 4);

// DHT configuration
#define DHTPIN 4 // Pin connected to DHT sensor
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// WiFi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Blynk credentials
char auth[] = "nbh5cOrGJNq5ijUZ61AlE4LsGYzwItW7";

// Telegram Bot credentials
#define BOT_TOKEN ""
#define CHAT_ID ""

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

// Timer for periodic updates
BlynkTimer timer;

void sendSensorDataToBlynk() {
  float Temperature = dht.readTemperature();
  float Humidity = dht.readHumidity();

  if (isnan(Temperature) || isnan(Humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send data to Blynk
  Blynk.virtualWrite(V0, Temperature);
  Blynk.virtualWrite(V1, Humidity);

  // Update LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(Temperature);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(Humidity);
  lcd.print(" %");

  // Send data to Telegram
  String message = "\u2705 Current Readings:\nTemperature: " + String(Temperature) + " °C\n" + "Humidity: " + String(Humidity) + " %";
  bot.sendMessage(CHAT_ID, message, "Markdown");
}

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize DHT sensor
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  lcd.clear();

  // Initialize Blynk
  Blynk.begin(auth, ssid, password);

  // Initialize Telegram
  client.setInsecure(); // For Telegram bot communication

  // Schedule periodic sensor data updates
  timer.setInterval(2000L, sendSensorDataToBlynk);
}

void loop() {
  Blynk.run();
  timer.run();
}