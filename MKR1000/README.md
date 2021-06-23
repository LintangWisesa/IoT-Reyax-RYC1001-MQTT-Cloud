# Arduino MKR1000 & Reyax RYC1001 MQTT Cloud

[![Arduino MKR1000 & Reyax RYC1001 MQTT Cloud](https://img.youtube.com/vi/RfUGAE88Bhw/0.jpg)](https://www.youtube.com/watch?v=RfUGAE88Bhw)

A simple MQTT connection tutorial between Arduino MKR1000 as the MQTT Client (publisher & subscriber) and Reyax RYC1001 MQTT IoT Cloud. Tools used in this tutorial: Arduino MKR1000, Arduino IDE 2.0, ```ArduinoMqttClient``` library, Reyax RYC1001 & MQTT.fx desktop application. Detailed tutorial can be [watched here](https://www.youtube.com/watch?v=RfUGAE88Bhw).

🎁 RYC1001 purchase link: [click here](http://amzn.to/3hAY5zp)

📁 MQTT.fx: [click here](https://softblade.de/en/download-2/)

📁 Arduino MKR1000: [click here](https://store.arduino.cc/usa/arduino-mkr1000)

📁 Arduino MQTT Client: [click here](https://github.com/arduino-libraries/ArduinoMqttClient)

<br>

### 📝 Source Code

```credential.h```: define credential values on a header file

  ```h
  #define WIFI_SSID "your_wifi_name"
  #define WIFI_PASS "your_wifi_pass"
  #define MQTT_BROKER "iot.reyax.com"
  #define MQTT_USER "your_reyax_username"
  #define MQTT_PASS "your_reyax_password"
  #define MQTT_CLID "your_reyax_clientid"
  #define MQTT_PORT 1883
  #define MQTT_TOPIC "lintang"
  ```

<br>

```pub.ino```: set Arduino MKR1000 as MQTT publisher

  ```arduino
  #include "credential.h"
  #include <ArduinoMqttClient.h>
  #include <WiFi101.h>

  WiFiClient wifiClient;
  MqttClient mqttClient(wifiClient);
  int count = 0;

  void setup() {
      Serial.begin(115200);
      while(WiFi.begin(WIFI_SSID, WIFI_PASS) != WL_CONNECTED){
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
  ```

<br>

```sub.ino```: set Arduino MKR1000 as MQTT subscriber

  ```arduino
  #include "credential.h"
  #include <ArduinoMqttClient.h>
  #include <WiFi101.h>

  WiFiClient wifiClient;
  MqttClient mqttClient(wifiClient);
  int count = 0;

  void setup() {
      Serial.begin(9600);
      while(WiFi.begin(WIFI_SSID, WIFI_PASS) != WL_CONNECTED){
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
  ```

<br>

#### 🍔 Lintang Wisesa

<br>

<a href="mailto: lintangwisesa@ymail.com">
  <img align="left" style="margin-right:10px" alt="lintang ymail" width="22px" src="https://camo.githubusercontent.com/b6e5ff081d7552ec05656de193794847e14d47ad/68747470733a2f2f732e79696d672e636f6d2f63762f61706976322f6d79632f6d61696c2f4d61696c5f694f535f6170705f69636f6e2e706e67" />
</a>

<a href="https://web.facebook.com/lintangbagus/">
  <img align="left" style="margin-right:10px" alt="lintang facebook" width="22px" src="https://camo.githubusercontent.com/a461898d72dd9f4c8c526dfcca9dfdc8a8c69605/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f352f35312f46616365626f6f6b5f665f6c6f676f5f253238323031392532392e7376672f3130323470782d46616365626f6f6b5f665f6c6f676f5f253238323031392532392e7376672e706e67" />
</a>

<a href="https://twitter.com/Lintang_Wisesa">
  <img style="margin-right:10px" align="left" alt="lintang twitter" width="24px" src="https://camo.githubusercontent.com/b6943877f3d8a1269974b9f820388403ee2b1978/68747470733a2f2f332e62702e626c6f6773706f742e636f6d2f2d4e786f754d6d7a32624f592f54385f61633937636573492f41414141414141414767302f65337659315f62646e62452f73313630302f547769747465722b6c6f676f2b323031322e706e67" />
</a>

<a href="https://www.youtube.com/user/lintangbagus">
  <img style="margin-right:10px" align="left" alt="lintang youtube" width="29px" src="https://upload.wikimedia.org/wikipedia/commons/4/42/YouTube_icon_%282013-2017%29.png" />
</a>

<a href="https://www.linkedin.com/in/lintangwisesa/">
  <img style="margin-right:10px" align="left" alt="lintang linkedin" width="24px" src="https://camo.githubusercontent.com/0d70d8c72e2f45755511d6799489dc49d0e325f0/68747470733a2f2f692e70696e696d672e636f6d2f6f726967696e616c732f63652f30392f33632f63653039336337323134616433353762623636356366643266363661386236622e706e67" />
</a>

<a href="https://github.com/LintangWisesa">
  <img style="margin-right:10px" align="left" alt="lintang github" width="23px" src="https://camo.githubusercontent.com/11406e7ae7d4716fcc586cddf450451576d71bef/68747470733a2f2f696d6167652e666c617469636f6e2e636f6d2f69636f6e732f7376672f32352f32353233312e737667" />
</a>

<a href="https://www.hackster.io/lintangwisesa">
  <img style="margin-right:10px" align="left" alt="lintang hackster" width="23px" src="https://user-images.githubusercontent.com/10383395/49821324-358fa080-fda0-11e8-8b00-def2a67fc598.png" />
</a>

<a href="https://lintangwisesa.github.io/me/">
  <img style="margin-right:10px" align="left" alt="lintang bio" width="24px" src="https://avatars2.githubusercontent.com/u/30064213?s=460&u=6640a1c3d5c1892283e1c273006755de8d32fa59&v=4" />
</a>