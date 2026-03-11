#include <PotentiometerInput.h>

// TODO: should be defined by IHAL method, e.g., a member function
//       maxInputQuant()
#define MAX_QUANT 1023

PotentiometerInput::PotentiometerInput(IHAL &hal, int pin) : m_hal{hal}, m_pin{pin} {}

float PotentiometerInput::getValue() {
	int quant = m_hal.analogRead(m_pin);

	return static_cast<float>(quant) / static_cast<float>(MAX_QUANT);
}
