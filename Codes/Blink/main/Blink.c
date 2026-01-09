#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led_pin GPIO_NUM_2

void app_main(void)
{
    gpio_reset_pin(led_pin);                        // Reset GPIO pin 2
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);
while (1)
{
    gpio_set_level(led_pin, 1);                     // Set GPIO pin 2 high
    vTaskDelay(pdMS_TO_TICKS(500));                 // Delay for 1 second
    gpio_set_level(led_pin, 0);                     // Set GPIO pin 2 low
    vTaskDelay(pdMS_TO_TICKS(500));                 // Delay for 1 second
}
}