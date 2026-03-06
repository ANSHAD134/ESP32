#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define SWITCH_PIN     0
#define LED_PIN        2

void app_main(void)
{
    // Configure GPIO Pin 0 as an Input
    gpio_reset_pin(SWITCH_PIN);                      // Reset GPIO pin 0
    gpio_set_direction(SWITCH_PIN, GPIO_MODE_INPUT); // Set GPIO pin 0 as input
    gpio_pullup_en(SWITCH_PIN);                      // Enable pull-up resistor for GPIO pin 0

    // Configure GPIO Pin 2 as an output
    gpio_reset_pin(LED_PIN);                         // Reset GPIO pin 2
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);   // Set GPIO pin 2 as output

    while (1)
    {
        // Check the state of the switch
        if (gpio_get_level(SWITCH_PIN) == 0)
        {
            gpio_set_level(LED_PIN, 1);  // Turn on the LED
        }
        else
        {
            gpio_set_level(LED_PIN, 0);  // Turn off the LED
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);  // Delay for 100ms
    }
    


}
