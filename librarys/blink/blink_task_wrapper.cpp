#include "Blink.hpp"
#include "FreeRTOS.h" // For FreeRTOS types like TaskHandle_t
#include "task.h"     // For vTaskDelay, etc.
#include "stdio.h"    // For printf

// Define the LED pin (can be passed via pvParameters if needed, but for simplicity, global)
// IMPORTANT: Make sure PICO_DEFAULT_LED_PIN is defined in pico/stdlib.h or your build system
#define WRAPPER_LED_PIN PICO_DEFAULT_LED_PIN

// This is the actual FreeRTOS task function.
// It is declared as extern "C" so the C linker can find it.
extern "C" void vBlinkTaskCpp(void *pvParameters) {
    // Create an instance of the C++ Blink class
    // This object will live for the duration of the task.
    Blink onboardLed(WRAPPER_LED_PIN);

    // Initialize the LED pin using the Blink class method
    onboardLed.init();
    printf("C++ Blink task initialized LED on pin %d.\n", WRAPPER_LED_PIN);

    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(500); // 500ms delay

    for (;;) {
        onboardLed.toggle(); // Toggle the LED state
        printf("LED %s! (via C++ Blink class)\n", onboardLed.is_on() ? "an" : "aus");

        // Wait for the next cycle
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}