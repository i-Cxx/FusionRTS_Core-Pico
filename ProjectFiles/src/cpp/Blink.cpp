// /home/hexzhen3x7/Entwicklungen/FusionRTS_Core-Pico/ProjectFiles/src/cpp/Blink.cpp
#include "Blink.hpp"
#include "pico/stdlib.h" // Make sure this is included for SDK functions

Blink::Blink(uint gpioPin) :
    _gpioPin(gpioPin),
    _currentState(false) { // Initialize with LED off state
    // Constructor primarily sets up the pin number
}

void Blink::init() {
    gpio_init(_gpioPin);
    gpio_set_dir(_gpioPin, GPIO_OUT);
    gpio_put(_gpioPin, _currentState); // Ensure LED is off initially
}

void Blink::toggle() {
    _currentState = !_currentState;
    gpio_put(_gpioPin, _currentState);
}

void Blink::blink_n_times(int count, unsigned long delay_ms) {
    for (int i = 0; i < count; ++i) {
        toggle();
        sleep_ms(delay_ms);
        toggle();
        sleep_ms(delay_ms);
    }
}