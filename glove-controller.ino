#include <WiFi.h>
#include <esp_now.h>

const int thumbPin = 25;
const int indexPin = 33;
const int middlePin = 34;
const int ringPin = 32;
const int pinkyPin = 35;

uint8_t receiverAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

struct SensorData {
  int thumb;
  int index;
  int middle;
  int ring;
  int pinky;
};

SensorData data;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  esp_now_add_peer(&peerInfo);
}

void loop() {
  data.thumb = analogRead(thumbPin);
  data.index = analogRead(indexPin);
  data.middle = analogRead(middlePin);
  data.ring = analogRead(ringPin);
  data.pinky = analogRead(pinkyPin);

  esp_now_send(receiverAddress, (uint8_t *)&data, sizeof(data));

  delay(20);
}
