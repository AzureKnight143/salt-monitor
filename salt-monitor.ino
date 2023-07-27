#include <HCSR04.h>
#include <ESP8266WiFi.h>
#include "arduino_secrets.h"

const char wifiSSID[] = SECRET_WIFI_SSID;
const char wifiPassword[] = SECRET_WIFI_PASSWORD;

const byte triggerPin = D4;
const byte echoPin = D3;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
  Serial.begin(9600);
  //Serial.setDebugOutput(true);
  delay(1000);
  Serial.println();
  connectToWifi();
}

void loop() {
  float distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  //ESP.deepSleep(5e6);
  delay(1000);
}

void connectToWifi() {
  WiFi.setPhyMode(WIFI_PHY_MODE_11G);
  WiFi.begin(wifiSSID, wifiPassword);
  Serial.print("Connecting to ");
  Serial.print(wifiSSID);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}