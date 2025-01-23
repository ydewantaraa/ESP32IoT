#define BLYNK_TEMPLATE_ID "TMPL6BhLnzYTX"
#define BLYNK_TEMPLATE_NAME "Pertemuan 3 Suhu dan Kelembapan"
#define BLYNK_AUTH_TOKEN "nbh5cOrGJNq5ijUZ61AlE4LsGYzwItW7"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "Username_Wifi";
const char *password = "Password_wifi";
char auth[] = "Blynk_Auth_Token";

WiFiClientSecure client;
const String botToken = "7956602949:AAEXDGJ58LcouCGsf89X8tv4KHRxS9HPbHI";
UniversalTelegramBot bot(botToken, client);

LiquidCrystal_I2C lcd(0x27, 16, 4);

const int suhuBatas = 30;
const int kelembabanBatas = 70;

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    client.setInsecure();

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Menghubungkan ke WiFi...");
    }
    Serial.println("Terhubung ke WiFi");

    Blynk.begin(auth, ssid, password);
    dht.begin();
    lcd.init();
    lcd.backlight();
}

void loop()
{
    Blynk.run();

    float suhu = dht.readTemperature();
    float kelembaban = dht.readHumidity();

    if (isnan(suhu) || isnan(kelembaban))
    {
        Serial.println("Gagal membaca data dari DHT11!");
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");
        delay(2000);
        return;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Suhu: ");
    lcd.print(suhu);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Kelembaban: ");
    lcd.print(kelembaban);
    lcd.print(" %");

    Blynk.virtualWrite(V0, suhu);
    Blynk.virtualWrite(V1, kelembaban);

    if (suhu > suhuBatas || kelembaban > kelembabanBatas)
    {
        String message = "Peringatan!\n";
        message += "Suhu: " + String(suhu) + " °C\n";
        message += "Kelembaban: " + String(kelembaban) + " %";

        bot.sendMessage("CHAT_ID", message, "Markdown");
        delay(60000);
    }

    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(" °C | Kelembaban: ");
    Serial.print(kelembaban);
    Serial.println(" %");

    delay(2000);
}