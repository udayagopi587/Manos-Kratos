#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>


typedef struct struct_message {
    int max_value;
    int min_value;
    int actual_value;
} struct_message;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

void setupSender();

void loopSender();

void sending();