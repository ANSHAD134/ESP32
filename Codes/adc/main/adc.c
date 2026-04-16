#include <stdio.h>
#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    adc_oneshot_unit_handle_t handle;           // Crated a handle
    adc_oneshot_unit_init_cfg_t init_config;    // Decelaration of init_config
    init_config.unit_id = ADC_UNIT_1;           // Selected ADC 1 unit
    adc_oneshot_new_unit(&init_config, &handle); // Passing handle config to new unit

    adc_oneshot_chan_cfg_t config;
    config.atten = ADC_ATTEN_DB_12;             // Voltage range is 0-3.3V can be counted as 0-4095
    config.bitwidth = ADC_BITWIDTH_DEFAULT;     // (12BIT ADC)
    adc_oneshot_config_channel(handle, ADC_CHANNEL_6, &config);// Passing handle, channel value and configuration settings to channel configuration structure.

    while(1)
    {
    int raw = 0;
    adc_oneshot_read(handle, ADC_CHANNEL_6, &raw);
    printf("ADC Raw Value = %d\n", raw);
    vTaskDelay(pdMS_TO_TICKS(1000));            // Delay of 1 second
    }
}
