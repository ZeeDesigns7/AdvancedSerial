#ifndef AdvancedSerial_h
#define AdvancedSerial_h

#include "Arduino.h"

class AdvancedSerial {
public:
    AdvancedSerial();
    void begin(unsigned long baudRate);

    // Generic print method for any type
    template<typename T>
    inline void print(const T& value) {
        Serial.print(value);
    }

    // Method to print a label and value directly
    template<typename T>
    void print(const char* label, const T& value, bool hex = false) {
        print(label);
        if (hex) {
            print(value, HEX); // Print in hexadecimal
        } else {
            print(value); // Regular print
        }
    }

    // Overload for printByte functionality
    void print(const char* label, byte* data, byte length) {
        print(label);
        for (int i = 0; i < length; i++) {
            if (data[i] < 0x10) {
                print("0");
            }
            print(data[i], HEX);
            if (i < length - 1) {
                print(" ");
            }
        }
    }

    // Overload for printByte functionality with println
    void println(const char* label, byte* data, byte length) {
        print(label, data, length);
        println();
    }

    // Overload for printing character array as hexadecimal bytes
    void print(const char* label, const char* str, byte dataLength) {
        print(label);
        for (byte i = 0; i < dataLength; i++) {
            byte byteValue = (byte)str[i];
            print(byteValue, HEX);
            if (i < dataLength - 1) {
                print(" ");
            }
        }
    }

    // Overload for printing character array as hexadecimal bytes with println
    void println(const char* label, const char* str, byte dataLength) {
        print(label, str, dataLength);
        println();
    }

    // Overload for printing character array as plain text
    void print(const char* label, const char* str) {
        print(label);
        print(str);
    }

    // Overload for printing character array as plain text with println
    void println(const char* label, const char* str) {
        print(label, str);
        println();
    }

    void print(const char* str); // For printing strings directly
    void print(byte value, bool hex = false); // Overload for byte type

    void println();
    void println(const char* str); // Methods with newline

    template<typename T>
    inline void println(const T& value) {
        print(value);
        Serial.println();
    }

    template<typename T>
    inline void println(const char* label, const T& value, bool hex = false) {
        print(label, value, hex);
        Serial.println();
    }
};

// Specialization for const char* type
template<>
inline void AdvancedSerial::print(const char* label, const char* const& value, bool hex) {
    Serial.print(label);
    Serial.print(value);
}

#endif