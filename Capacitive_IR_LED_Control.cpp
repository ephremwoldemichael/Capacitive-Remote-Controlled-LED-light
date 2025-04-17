#include <iostream>
#include <thread>
#include <chrono>

// Simulating the capacitive touch sensor and IR remote
// In a real embedded system, these would interact with hardware peripherals.

// Mock functions to simulate hardware interactions
bool readTouchSensor() {
    // Simulate capacitive touch sensor (returns true when touched)
    static bool state = false;
    state = !state;  // Toggle state for testing
    return state;
}

long int readIRRemote() {
    // Simulate an IR remote (returns an example code)
    // In practice, you'll use a library to decode the IR signal
    return 0xFF18E7;  // Example code for a specific button
}

void controlLED(bool state) {
    // Simulate controlling an LED
    if (state) {
        std::cout << "LED is ON" << std::endl;
    } else {
        std::cout << "LED is OFF" << std::endl;
    }
}

int main() {
    bool ledState = false;  // Track the LED state

    while (true) {
        // Check for capacitive touch input to toggle LED
        if (readTouchSensor()) {
            ledState = !ledState;  // Toggle LED state
            controlLED(ledState);
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // debounce delay
        }

        // Check for IR remote input to toggle LED
        long int irCode = readIRRemote();
        std::cout << "IR code detected: " << std::hex << irCode << std::endl;

        if (irCode == 0xFF18E7) {  // Check if the IR button matches
            ledState = !ledState;  // Toggle LED state
            controlLED(ledState);
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // debounce delay
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Prevent high CPU usage
    }

    return 0;
}
