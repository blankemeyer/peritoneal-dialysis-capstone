#ifndef IOUTPUT_H
#define IOUTPUT_H

/**
 * Output Interface
 *
 * Has a setValue method that reads from an analog input and returns a
 * value between 0 and 1
 */

class IOutput {
public:
	virtual ~IOutput() = default;

	/**
	 * Returns the last value set.
	 */
	virtual float getValue() = 0;

	/**
	 * Writes a value to this output.
	 *
	 * @param value The floating-point value to set. Must be in the range
	 *              [0, 1].
	 */
	virtual void setValue(float value) = 0;
};

#endif // IOUTPUT_H
