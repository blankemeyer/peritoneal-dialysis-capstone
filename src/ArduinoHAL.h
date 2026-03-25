/**
 * @file ArduinoHAL.h
 */

#ifndef ARDUINO_HAL_H
#define ARDUINO_HAL_H

#include <IHAL.h>

/**
 * Arduino Hardware Abstraction Layer
 *
 * Implementation of the HAL for Arduino. This class provides Arduino-specific
 * implementations of all hardware operations defined in the IHAL interface.
 */

class ArduinoHAL : public IHAL {
public:
	ArduinoHAL(int serialBaud);

	AnalogValue analogRead(int pin) override;
	void analogWrite(int pin, AnalogValue value) override;
	AnalogValue getMaxAnalogReadQuant() const override;
	AnalogValue getMaxAnalogWriteQuant() const override;

	DigitalValue digitalRead(int pin) override;
	void digitalWrite(int pin, DigitalValue value) override;

	void beginSerial() override;
	size_t print(const char *s) override;
	size_t println(const char *s) override;

	void delayMs(unsigned long durationMs) override;
	unsigned long getTimeMs() override;

private:
	static constexpr AnalogValue MAX_ANALOG_READ_QUANT = 1023;
	static constexpr AnalogValue MAX_ANALOG_WRITE_QUANT = 255;

	int m_serialBaud;
};

#endif // ARDUINO_HAL_H
