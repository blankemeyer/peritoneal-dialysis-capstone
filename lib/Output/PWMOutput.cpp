#include <PWMOutput.h>
#include <assert.h>

PWMOutput::PWMOutput(IHAL &hal, int pin)
		: m_hal{hal}, m_pin{pin}, m_value{0.f} {}

float PWMOutput::getValue() {
	return m_value;
}

void PWMOutput::setValue(float dutyCycle) {
	assert(dutyCycle >= 0.f);
	assert(dutyCycle <= 1.f);

	int maxQuant = m_hal.getMaxAnalogWriteQuant();
	int quant = static_cast<int>(dutyCycle * static_cast<float>(maxQuant));

	m_hal.analogWrite(m_pin, quant);
	m_value = static_cast<float>(quant) / static_cast<float>(maxQuant);
}
