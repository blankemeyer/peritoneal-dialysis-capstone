#include <SerialDisplay.h>
#include <stdio.h>

SerialDisplay::SerialDisplay(IHAL &hal) : hal(hal) {}

void SerialDisplay::initialize() {
	hal.beginSerial();
}

void SerialDisplay::update(float channel1Power, float channel2Power) {
	snprintf(
		string_buffer, sizeof(string_buffer),
		"Wire 1 Power Level:\t%.0f%%\n"
		"Wire 2 Power Level:\t%.0f%%\n",
		channel1Power * 100, channel2Power * 100
	);

	hal.println(string_buffer);
}
