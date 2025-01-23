#include <WiFi.h>

const char* ssid = "Nama_WiFi";
const char* password = "Password_WiFi";
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    Serial.print("Menghubungkan ke WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nTersambung ke WiFi");
    Serial.print("Alamat IP ESP32: ");
    Serial.println(WiFi.localIP());
}

void loop() {}