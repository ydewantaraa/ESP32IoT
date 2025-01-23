#define BLYNK_TEMPLATE_ID "TMPL6Tel2ITVG"
#define BLYNK_TEMPLATE_NAME "Monitoring Suhu dan Kelembapan"
#define BLYNK_AUTH_TOKEN "WIZxdFrb212n4kA1V0IfmNua5rQPOcYf"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "Nama_WiFi";
char pass[] = "Password_WiFi";

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    Serial.println("Menghubungkan ke Blynk dan memulai sensor DHT11");
}

void loop() {
    Blynk.run();
    bacaDanKirimData();
    delay(2000);
}

void bacaDanKirimData() {
    float suhu = dht.readTemperature();
    float kelembapan = dht.readHumidity();

    if (isnan(suhu) || isnan(kelembapan)) {
        Serial.println("Gagal membaca data dari DHT11!");
        return;
    }

    Blynk.virtualWrite(V1, suhu);
    Blynk.virtualWrite(V2, kelembapan);

    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(" °C | Kelembapan: ");
    Serial.print(kelembapan);
    Serial.println(" %");
}