# AdvancedSerial
AdvancedSerial provides enhanced serial communication capabilities for Arduino, enabling more flexible and detailed serial outputs. It extends the basic functionality of the Arduino Serial library, allowing automatic detection and handling of various data types, and the capability to print values in both their native format and as hexadecimal byte values.

# Features
- **Flexible Data Printing**: Print any standard Arduino data type (int, float, char, etc.) easily.
- **Hexadecimal Output**: Direct support for printing data in hexadecimal format, useful for debugging and data visualization.
- **Advanced Formatting**: Includes methods to print labels followed by values, simplifying the process of logging and data output.
- **Template Functions**: Utilize template functions for easy adaptation to different data types without overloaded functions cluttering your codebase.

# Installation
1. Download the library as a `.zip` file.
2. Open your Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...` and select the downloaded file.
3. Restart the Arduino IDE to see the library in the `Sketch > Include Library` menu.

# Public functions

## _void_ begin(_unsigned long_ baudRate)
Initialize serial communication with specified baud rate.

## _void_ print(_const char*_ str)
Print a string.

## _void_ println(_const char*_ str)
Print a string followed by a new line.

## _template<typename T>_ print(_const char*_ label, _const T&_ value, _bool_ hex = false)
Print a label followed by a value, optionally in hex format.

## _void_ println(_const char*_ label, _const char*_ encryptedData, _byte_ dataLength)
Print hexadecimal byte values with labels, followed by a new line.

# Example
Here is a simple example on how to use the AdvancedSerial library in your Arduino projects:

```cpp
#include <Arduino.h>
#include "AdvancedSerial.h"

AdvancedSerial mySerial;

void setup() {
  mySerial.begin(115200);
  
  // Print different types of variables
  mySerial.println("Testing AdvancedSerial with different variable types");
  int intValue = -123;
  mySerial.println("Integer:", intValue);
  mySerial.println("Integer (hex):", intValue, true);
}

void loop() {
  // Continuously perform tasks
}
```

# Contribution
Contributions to the library are welcome. Please feel free to fork the repository, make changes, and submit pull requests.


# License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
