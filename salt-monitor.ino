#include <HCSR04.h>

const byte triggerPin = D4;
const byte echoPin = D3;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  delay(1000);
}