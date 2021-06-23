#include "credential.h"
#include <ArduinoMqttClient.h>
#include "WiFi.h"

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
int count = 0;

void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while(WiFi.status() != WL_CONNECTED){
        Serial.print("."); 
        delay(500);
    }
    Serial.println("Terhubung ke WiFi!");
    mqttClient.setId(MQTT_CLID);
    mqttClient.setUsernamePassword(MQTT_USER, MQTT_PASS);
    if (!mqttClient.connect(MQTT_BROKER, MQTT_PORT)){
        Serial.println("Gagal terhubung ke MQTT Cloud!");
        Serial.println(mqttClient.connectError());
    }
    Serial.println("Terhubung ke MQTT Cloud!");
}

void loop() {
    mqttClient.poll();
    mqttClient.beginMessage(MQTT_TOPIC);
    mqttClient.print("Data = ");
    mqttClient.print(count);
    mqttClient.endMessage();
    Serial.print("Terkirim: Data = ");
    Serial.println(count);
    count++;
    delay(2000);
}