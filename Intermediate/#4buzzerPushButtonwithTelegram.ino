#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

// WiFi credentials
const char* ssid = ""; // Ganti dengan nama WiFi Anda
const char* password = ""; // Ganti dengan password WiFi Anda

// Telegram credentials
const char* botToken = ""; // Ganti dengan token bot Telegram Anda
const char* chatID = ""; // Ganti dengan chat ID Telegram Anda

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

// Pin definitions
const int buttonPin = 12;  // Pin untuk push button
const int buzzerPin = 13;  // Pin untuk buzzer

// State variable
bool alarmState = false; // Status alarm

void setup() {
  Serial.begin(115200);

  // Setup pins
  pinMode(buttonPin, INPUT_PULLUP); // Button dengan internal pull-up
  pinMode(buzzerPin, OUTPUT);

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  client.setInsecure(); // Disable certificate verification
}

void loop() {
  // Check button press
  if (digitalRead(buttonPin) == LOW) {
    delay(200); // Simple debounce
    alarmState = !alarmState; // Toggle alarm state

    if (alarmState) {
      Serial.println("Alarm ON");
      digitalWrite(buzzerPin, HIGH); // Turn on buzzer
      bot.sendMessage(chatID, "\u26A0 Alarm is ON!", "Markdown"); // Send Telegram message
    } else {
      Serial.println("Alarm OFF");
      digitalWrite(buzzerPin, LOW); // Turn off buzzer
      bot.sendMessage(chatID, "\u2705 Alarm is OFF!", "Markdown"); // Send Telegram message
    }

    while (digitalRead(buttonPin) == LOW) {
      delay(10); // Wait until button is released
    }
  }

  delay(100); // Small delay to avoid rapid toggles
}
