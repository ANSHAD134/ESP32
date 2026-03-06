#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN     2

void app_main(void)
{
    // Configure GPIO Pin 2 as an Output
    gpio_reset_pin(LED_PIN);                        // Reset GPIO pin 2
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);  // Set GPIO pin 2 as output

    while (1)
    {
        gpio_set_level(LED_PIN, 1);                 // Set GPIO pin 2 high
        vTaskDelay(1000 / portTICK_PERIOD_MS);      // Delay for 1000ms (1 second)
        gpio_set_level(LED_PIN, 0);                 // Set GPIO pin 2 low
        vTaskDelay(1000 / portTICK_PERIOD_MS);      // Delay for 1000ms (1 second)
    }
    
}
