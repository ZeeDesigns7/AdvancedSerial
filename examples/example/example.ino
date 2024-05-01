//Example.ino

#include <Arduino.h>
#include "AdvancedSerial.h"

AdvancedSerial mySerial;

void setup() {
  mySerial.begin(115200);
  mySerial.println("Testing AdvancedSerial with different variable types");
  mySerial.println();

  // Integer types
  int intValue = -1234;
  unsigned int uintValue = 5678;
  mySerial.println("int:\t\t", intValue);
  mySerial.println("int (hex):\t\t", intValue, true);
  mySerial.println("unsigned int:\t", uintValue);
  mySerial.println("unsigned int (hex):\t", uintValue, true);
  mySerial.println();

  // Floating-point types
  float floatValue = 3.14159;
  double doubleValue = 2.71828;
  mySerial.println("float:\t\t", floatValue);
  mySerial.println("float (hex):\t\t", floatValue, true);
  mySerial.println("double:\t\t", doubleValue);
  mySerial.println("double (hex):\t\t", doubleValue), true;
  mySerial.println();

  // Character types
  char charValue = 'A';
  mySerial.println("char:\t\t", charValue);
  mySerial.println("char (hex):\t\t", charValue, true);
  mySerial.println();

  // Boolean type
  bool boolValue = true;
  mySerial.println("bool:\t\t", boolValue);
  mySerial.println("bool (hex):\t\t", boolValue);
  mySerial.println();

  // String type
  const char* stringValue = "Hello, AdvancedSerial!";
  mySerial.println("string:\t\t", stringValue);
  mySerial.println("string (hex):\t\t", stringValue, true);
  mySerial.println("string:\t\t", "Hello again");
  mySerial.println("string:\t\t", "Hello again", true);
  mySerial.println();

  // Byte array
  byte byteArray[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
  mySerial.println("byte array:\t\t", byteArray, sizeof(byteArray));
  mySerial.println();

  // Hexadecimal representation
  int hexValue = 0xABCDEF;
  mySerial.println("hexadecimal:\t", hexValue);
  mySerial.println("hexadecimal (hex):\t", hexValue, true);
  mySerial.println();

}

void loop() {
  // Empty loop
}
