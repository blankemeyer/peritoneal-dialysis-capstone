#include <PotentiometerInput.h>

PotentiometerInput::PotentiometerInput(IHAL &hal, int pin)
		: m_hal{hal}, m_pin{pin} {}

float PotentiometerInput::getValue() {
	int quant = m_hal.analogRead(m_pin);
	int maxQuant = m_hal.getMaxAnalogReadQuant();

	return static_cast<float>(quant) / static_cast<float>(maxQuant);
}
