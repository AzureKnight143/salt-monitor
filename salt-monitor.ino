#include <HCSR04.h>

const byte triggerPin = D4;
const byte echoPin = D3;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  float distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  ESP.deepSleep(5e6);
  delay(1000);
}