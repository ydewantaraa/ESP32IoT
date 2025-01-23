#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();
    Serial.println("Mulai membaca sensor DHT11");
}

void loop() {
    delay(2000);

    float suhu = dht.readTemperature();

    float kelembaban = dht.readHumidity();

    if (isnan(suhu) || isnan(kelembaban)) {
        Serial.println("Gagal membaca data dari DHT11!");
        return;
    }

    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(" °C | Kelembaban: ");
    Serial.print(kelembaban);
    Serial.println(" %");
}