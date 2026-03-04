#include "PotentiometerInput.h"

#include <assert.h>

#define MAX_QUANT 1023

PotentiometerInput::PotentiometerInput(IHAL &hal, int pin) : m_hal{hal}, m_pin{pin} {}

float PotentiometerInput::getValue() {
	int quant = m_hal.analogRead(m_pin);

	return (float)quant / (float)MAX_QUANT;
}
