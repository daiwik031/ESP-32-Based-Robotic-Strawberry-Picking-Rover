#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servoPin1 = 13;
const int servoPin2 = 12;
const int servoPin3 = 14;
const int servoPin4 = 27;

struct SensorData {
  int thumb;
  int index;
  int middle;
  int ring;
  int pinky;
};

SensorData data;

void onReceive(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  if (len == sizeof(data)) {
    memcpy(&data, incomingData, sizeof(data));

    int a1 = map(data.thumb, 0, 4095, 0, 180);
    int a2 = map(data.index, 0, 4095, 0, 180);
    int a3 = map(data.middle, 0, 4095, 0, 180);
    int a4 = map(data.ring, 0, 4095, 0, 180);

    a1 = constrain(a1, 0, 180);
    a2 = constrain(a2, 0, 180);
    a3 = constrain(a3, 0, 180);
    a4 = constrain(a4, 0, 180);

    servo1.write(a1);
    servo2.write(a2);
    servo3.write(a3);
    servo4.write(a4);
  }
}

void setup() {
  Serial.begin(115200);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onReceive);
}

void loop() {
}
