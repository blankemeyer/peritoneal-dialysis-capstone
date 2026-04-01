#include <CatheterController.h>
#include <PWMOutput.h>
#include <PotentiometerInput.h>

/**
 * CatheterController Implementation
 */
CatheterController::CatheterController(
	IHAL &hal, int inputPin1, int outputPin1, int inputPin2, int outputPin2,
	IDisplay &display
)
		: input1(hal, inputPin1), output1(hal, outputPin1), input2(hal, inputPin2),
			output2(hal, outputPin2), channel1(input1, output1),
			channel2(input2, output2), display(display) {}

void CatheterController::update() {
	channel1.update();
	channel2.update();
	float output1 = channel1.getOutputValue();
	float output2 = channel2.getOutputValue();
	display.update(output1, output2);
}
