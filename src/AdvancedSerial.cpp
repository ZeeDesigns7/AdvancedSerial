//AdancedSerial.cpp

#include "AdvancedSerial.h"

AdvancedSerial::AdvancedSerial() {
    // Constructor is now empty or used for other initializations
}

void AdvancedSerial::begin(unsigned long baudRate) {
    Serial.begin(baudRate); // Initialize Serial with the user-defined baud rate
}

void AdvancedSerial::print(const char* str) {
    Serial.print(str);
}

void AdvancedSerial::print(byte value, bool hex) {
    if (hex) {
        // Print byte value in hexadecimal format with leading zero
        if (value < 16) {
            Serial.print("0");
        }
        Serial.print(value, HEX);
    } else {
        Serial.print(value);
    }
}

void AdvancedSerial::println() {
    Serial.println();
}

void AdvancedSerial::println(const char* str) {
    Serial.println(str);
}