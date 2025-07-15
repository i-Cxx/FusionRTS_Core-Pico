#ifndef BLINK_HPP
#define BLINK_HPP

#include "pico/stdlib.h" // For GPIO functions and sleep_ms

class Blink {
public:
    // Constructor: Takes the GPIO pin number
    Blink(uint gpioPin);

    // Method to initialize the GPIO pin
    void init();

    // Method to toggle the LED state
    void toggle();

    // Method to blink the LED a certain number of times with a delay
    void blink_n_times(int count, unsigned long delay_ms);

    // NEU: Methode, um den aktuellen Zustand der LED abzufragen
    bool is_on() const { return _currentState; } // inline implementation for simplicity

private:
    uint _gpioPin;
    bool _currentState;
};

#endif // BLINK_HPP