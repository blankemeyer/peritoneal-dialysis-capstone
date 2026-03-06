#if defined(ARDUINO_AVR_UNO)

#include <Arduino.h>

void setup() {}

void loop() {}

#else

#include <iostream>

int main() {
	std::cout << "Hello, World!\n";
}

#endif
