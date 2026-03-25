#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_http_client.h"
#include "esp_adc/adc_oneshot.h"
#include "driver/gpio.h"
#include "cJSON.h"
#include "esp_tls.h"
#include "esp_crt_bundle.h"

#define WIFI_SSID               "WIFI_SSID"
#define WIFI_PASS               "WIFI_PASS"
#define LM35_CONTROL_PIN        GPIO_NUM_33
#define FIREBASE_URL            "YOURFIREBASE_URL/sensor_data.json"
#define SENSOR_READ_INTERVAL_MS 5000
#define TEMP_CALIBRATION_OFFSET 9.5                         // Adjust if readings are consistently off

static const char *TAG = "IOT_APP";

void app_main(void)
{

}