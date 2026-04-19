#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "nvs_flash.h"
#include "esp_adc/adc_oneshot.h"

#define SSID        "Airtel_azha_2428"
#define PASSWORD    "air74947"

#define TEMP_CALIBRATION_OFFSET      9.5         // Adjust if readings are consistently off

static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) 
    {
        printf("Wifi started\n");
        esp_wifi_connect();
    }
    else if(event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        printf("Connection successful\n");
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        printf("Got IP: " IPSTR "\n",IP2STR(&event->ip_info.ip));
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        printf("Wifi disconnected\n");
        wifi_event_sta_disconnected_t* event = (wifi_event_sta_disconnected_t*) event_data;
        printf("Reason: %d\n", event->reason);
        esp_wifi_connect();
    }
}

void app_main(void)
{
    //Wifi Configuration
    nvs_flash_init();
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);

    wifi_config_t config = {
    .sta = {
    .ssid = SSID,
    .password = PASSWORD,
    },
    };

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &config);
    esp_wifi_start();

    // ADC Configuration
    adc_oneshot_unit_handle_t handle;            // Crated a handle
    adc_oneshot_unit_init_cfg_t init_config;     // Decelaration of init_config
    init_config.unit_id = ADC_UNIT_1;            // Selected ADC 1 unit
    adc_oneshot_new_unit(&init_config, &handle); // Passing handle config to new unit

    adc_oneshot_chan_cfg_t adc_config;
    adc_config.atten = ADC_ATTEN_DB_12;              // Voltage range is 0-3.3V can be counted as 0-4095
    adc_config.bitwidth = ADC_BITWIDTH_DEFAULT;      // (12BIT ADC)
    adc_oneshot_config_channel(handle, ADC_CHANNEL_6, &adc_config);// Passing handle, channel value and configuration settings to channel configuration structure.

    while(1)
    {
    int raw = 0;
    adc_oneshot_read(handle, ADC_CHANNEL_6, &raw);
    float milliVolts = (raw * 3300.0) / 4095.0;
    float tempC = (milliVolts / 10.0) + TEMP_CALIBRATION_OFFSET;
    printf("Temperature = %0.2f C\n", tempC);
    vTaskDelay(pdMS_TO_TICKS(15000));             // Delay of 15 second
    }
}
