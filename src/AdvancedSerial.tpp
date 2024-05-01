//AdvancedSerial.tpp

#include "AdvancedSerial.h"

template<typename T>
void AdvancedSerial::print(const T& value) {
    Serial.print(value);
}

// Method to print a label and value
template<typename T>
void AdvancedSerial::print(const char* label, const T& value, bool hex) {
    Serial.print(label);
    if (hex && (std::is_integral<T>::value || std::is_enum<T>::value)) {
        Serial.print(value, HEX); // Print in hexadecimal
    } else {
        Serial.print(value); // Regular print
    }
}

// Define the specialization outside the class scope
template<>
void AdvancedSerial::print(const char* label, const char* const& value, bool hex) {
    Serial.print(label);
    Serial.print(value);
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

template<typename T>
void AdvancedSerial::println(const T& value) {
    print(value);
    Serial.println();
}

template<typename T>
void AdvancedSerial::println(const char* label, const T& value, bool hex) {
    print(label, value, hex);
    Serial.println();
}