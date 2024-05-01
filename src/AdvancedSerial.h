//AdvancedSerial.h

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

    // Overload for printHexChar functionality
    void print(const char* label, const char* encryptedData, byte dataLength) {
        print(label);
        for (int i = 0; i < dataLength; i++) {
            byte byteValue = (byte)encryptedData[i]; // Cast to byte to handle unsigned data
            if (byteValue < 16) {
                print("0"); // Print leading zero for single digit hex numbers
            }
            print(byteValue, HEX); // Print byte as hex
            print(" "); // Print space for readability between hex values
        }
    }

    // Overload for printHexChar functionality with println
    void println(const char* label, const char* encryptedData, byte dataLength) {
        print(label, encryptedData, dataLength);
        println(); // New line after printing all hex values
    }

    // Overload for printText functionality
    void println(const char* label, const char* text) {
        char buffer[256]; // Ensure the buffer is sized appropriately for your messages
        snprintf(buffer, sizeof(buffer), "%s%s", label, text);
        println(buffer);
    }

    // Overload for printing string as hexadecimal bytes
    void println(const char* label, const char* str, bool hex) {
        print(label);
        if (hex) {
            for (size_t i = 0; str[i] != '\0'; i++) {
                byte byteValue = (byte)str[i];
                if (byteValue < 16) {
                    print("0");
                }
                print(byteValue, HEX);
                print(" ");
            }
            println();
        } else {
            println(str);
        }
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