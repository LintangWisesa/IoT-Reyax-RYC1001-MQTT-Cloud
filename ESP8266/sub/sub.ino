#include "credential.h"
#include <ArduinoMqttClient.h>
#include <ESP8266WiFi.h>

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
int count = 0;

void setup() {
    Serial.begin(9600);
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
    mqttClient.subscribe(MQTT_TOPIC);
}

void loop() {
    if (mqttClient.parseMessage()){
        while (mqttClient.available()){
        Serial.print((char)mqttClient.read());
        }
        Serial.println();
    }
}