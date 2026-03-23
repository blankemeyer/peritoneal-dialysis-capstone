/**
 * @file SerialDisplay.h
 */

#ifndef SERIAL_DISPLAY_H
#define SERIAL_DISPLAY_H

#include <IDisplay.h>
#include <IHAL.h>

/**
 * Implementation of `IDisplay` that uses the HAL to write to the serial output.
 */
class SerialDisplay : public IDisplay {
private:
	IHAL &hal;
	char string_buffer[128];

public:
	SerialDisplay(IHAL &hal);
	void initialize() override;
	void update(float channel1Power, float channel2Power) override;
};

#endif // SERIAL_DISPLAY_H
