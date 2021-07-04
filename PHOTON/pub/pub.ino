#include <MQTT.h>

void callback(char* topic, byte* payload, unsigned int length);
MQTT client("iot.reyax.com", 1883, callback);
int count = 0;
char str[8];

void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;
    Serial.println(p);
}

void setup() {
    Serial.begin(9600);
    WiFi.on();
    WiFi.setCredentials("wifi_name", "wifi_pass");
    WiFi.connect();
    waitUntil(WiFi.ready);
    while (WiFi.localIP() == IPAddress()) {
        delay(10);
    }
    client.connect("mqtt_clientId", "mqtt_username", "mqtt_password");
}

void loop() {
    if (client.isConnected()) {
        client.loop();
        client.publish("lintang", itoa(count, str, 10));
	Serial.println(itoa(count, str, 10));
    }
    delay(2000);
    count++;
}