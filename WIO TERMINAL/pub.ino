#include "credential.h"
#include "rpcWiFi.h"
#include <ArduinoMqttClient.h>
#include"TFT_eSPI.h"
TFT_eSPI tft;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
const char* ssid = WIFI_SSID;
const char* password =  WIFI_PASS;
int count = 0;

void setup() {
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
 
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
 
    tft.setTextSize(2);
    tft.drawString("Lagi proses...", 20, 20);
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        WiFi.begin(ssid, password);
    }
    tft.setTextSize(2);
    tft.drawString("Terhubung ke WiFi!", 20, 50);

    mqttClient.setId(MQTT_CLID);
    mqttClient.setUsernamePassword(MQTT_USER, MQTT_PASS);
    if (!mqttClient.connect(MQTT_BROKER, MQTT_PORT)){
        tft.setTextSize(2);
        tft.drawString("MQTT connection failed", 20, 80);
    }
    tft.setTextSize(2);
    tft.drawString("Terhubung ke MQTT Cloud!", 20, 80);
}
 
void loop() {
    mqttClient.poll();
    mqttClient.beginMessage(MQTT_TOPIC);
    mqttClient.print("Data = ");
    mqttClient.print(count);
    mqttClient.endMessage();
    tft.setTextSize(10);
    tft.drawString(String(count), 20, 130);
    count++;
    delay(3000);
}