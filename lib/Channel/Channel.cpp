#include <Channel.h>

Channel::Channel(IInput &input, IOutput &output)
		: input(input), output(output) {}

void Channel::update() {
	float inputValue = input.getValue();
	output.setValue(inputValue);
}

float Channel::getOutputValue() {
	return output.getValue();
}
