/**
 * @file IInput.h
 */

#ifndef IINPUT_H
#define IINPUT_H

/**
 * Input Interface
 *
 * Has a getValue method that reads from an analog input and returns a
 * value between 0 and 1
 */
class IInput {
public:
	virtual ~IInput() = default;

	/**
	 * Samples this input.
	 *
	 * @return The floating-point value of this input, normalized to the range
	 *         [0, 1].
	 */
	virtual float getValue() = 0;
};

#endif // IINPUT_H
