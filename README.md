# salt-monitor

A distance monitor for my water softener salt tank using a Ultrasonic Distance Sensor. It does the following in a loop:

- Connects to the wifi network configured in the arduino_secrets.h.
- Scans distance until it gets a result or fails 6 times.
- Sends distance or error to serial monitor.
- Goes to deep sleep for the configured time, currently 5 seconds.

## Setup

Create an `arduino_secrets.h` file and add the following:

```
#define SECRET_WIFI_SSID "YOUR SSID"
#define SECRET_WIFI_PASSWORD "YOUR PASSWORD"
```

## Pin Layout

- Board D1 - Sensor Trig
- Board D2 - Sensor Echo
- Board 5V - Sensor Vcc
- Board G - Sensor Gnd
- Board D0 - Board RST (wakes board from deep sleep)
