/**
 * @file Channel.h
 */

#ifndef CHANNEL_H
#define CHANNEL_H

#include <IInput.h>
#include <IOutput.h>

/**
 * Represents a control channel from one input to one output.
 */
class Channel {
private:
	IInput &input;
	IOutput &output;

public:
	/**
	 * @param input The input source (e.g., potentiometer)
	 * @param output The output (e.g., a PWM pin)
	 */
	Channel(IInput &input, IOutput &output);

	/**
	 * Read from the input and write to the output.
	 */
	void update();

	/**
	 * @return The current output value between zero and one.
	 */
	float getOutputValue();
};

#endif // CHANNEL_H
