#include <WiFi.h>
#include <esp_now.h>

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

    Serial.print(data.thumb);
    Serial.print(",");
    Serial.print(data.index);
    Serial.print(",");
    Serial.print(data.middle);
    Serial.print(",");
    Serial.print(data.ring);
    Serial.print(",");
    Serial.println(data.pinky);
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onReceive);
}

void loop() {
}

