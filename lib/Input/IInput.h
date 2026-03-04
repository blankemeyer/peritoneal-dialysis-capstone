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
	virtual float getValue() = 0;
};

#endif // IINPUT_H
