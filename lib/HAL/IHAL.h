#ifndef IHAL_H
#define IHAL_H

/**
 * Hardware Abstraction Layer Interface
 *
 * This interface defines all hardware operations needed by the application.
 * Different platforms (Arduino, Raspberry Pi, etc.) implement this interface
 * to provide platform-specific functionality.
 */

class IHAL {
public:
	// Analog I/O
	virtual int analogRead(int pin) = 0;
	virtual void analogWrite(int pin, int value) = 0;

	// Serial print functions

	// Timing
	virtual void delay(unsigned long ms) = 0;
	virtual unsigned long millis() = 0;
};

#endif // IHAL_H
