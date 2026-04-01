/**
 * @file IHAL.h
 */

#ifndef IHAL_H
#define IHAL_H

#include <stddef.h>

using AnalogValue = int;

enum DigitalValue {
	DigitalLow = 0,
	DigitalHigh = 1,
};

/**
 * Hardware Abstraction Layer Interface
 *
 * This interface defines all hardware operations needed by the application.
 * Different platforms (Arduino, Raspberry Pi, etc.) implement this interface
 * to provide platform-specific functionality.
 */
class IHAL {
public:
	virtual ~IHAL() = default;

	// Analog I/O

	/**
	 * Samples an analog input pin.
	 *
	 * The pin must be valid for analog reading.
	 *
	 * @param pin The pin number.
	 * @return The quantized value in the range <tt>[0, N]</tt> where \c N is
	 *         the maximum value indicated by \ref getMaxAnalogReadQuant.
	 */
	virtual AnalogValue analogRead(int pin) = 0;

	/**
	 * Drives an analog output pin.
	 *
	 * The pin must be valid for analog writing.
	 *
	 * @param pin The pin number.
	 * @param value The quantized value to write. Must be in the range
	 *              <tt>[0, N]</tt> where \c N is the maximum value indicated by
	 *              \ref getMaxAnalogWriteQuant.
	 */
	virtual void analogWrite(int pin, AnalogValue value) = 0;

	/**
	 * Returns the maximum quantized value of an analog read.
	 *
	 * For an analog read, a real input value in the range <tt>[0, 1]</tt> can
	 * be obtained by dividing the quantized value by this maximum value.
	 */
	virtual AnalogValue getMaxAnalogReadQuant() const = 0;

	/**
	 * Returns the maximum quantized value of an analog write.
	 *
	 * For an analog write, a real output value in the range <tt>[0, 1]</tt> can
	 * be converted to a quantized value by multiplying by this maximum value.
	 */
	virtual AnalogValue getMaxAnalogWriteQuant() const = 0;

	// Digital I/O

	/**
	 * Samples a digital input pin.
	 *
	 * The pin must be valid for digital reading.
	 *
	 * @param pin The pin number.
	 * @return The digital value.
	 */
	virtual DigitalValue digitalRead(int pin) = 0;

	/**
	 * Drives a digital output pin.
	 *
	 * The pin must be valid for digital writing.
	 *
	 * @param pin The pin number.
	 * @param value The digital value to write.
	 */
	virtual void digitalWrite(int pin, DigitalValue value) = 0;

	// Serial

	/**
	 * Initializes the serial interface.
	 *
	 * This method must be called before using the serial print functions.
	 */
	virtual void beginSerial() = 0;

	/**
	 * Transmits an ASCII string over serial.
	 *
	 * @param s The NUL-terminated ASCII string to write.
	 * @return The number of bytes written.
	 */
	virtual size_t print(const char *s) = 0;

	/**
	 * Transmits an ASCII string with trailing newline over serial.
	 *
	 * The string @a s is written, followed by an appropriate end-of-line
	 * indicator (e.g., CR-LF).
	 *
	 * @param s The NUL-terminated ASCII string to write.
	 * @return The number of bytes written.
	 */
	virtual size_t println(const char *s) = 0;

	// Timing

	/**
	 * Suspends execution for a specified duration in milliseconds.
	 *
	 * @param durationMs The duration in milliseconds.
	 */
	virtual void delayMs(unsigned long durationMs) = 0;

	/**
	 * Returns the number of milliseconds elapsed since the start of execution,
	 * modulo <tt>ULONG_MAX-1</tt>.
	 */
	virtual unsigned long getTimeMs() = 0;
};

#endif // IHAL_H
