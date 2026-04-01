/**
 * @file PWMOutput.h
 */

#ifndef PWM_OUTPUT_H
#define PWM_OUTPUT_H

#include <IHAL.h>
#include <IOutput.h>

/**
 * PWM Output
 *
 * Controls a PWM output pin. Accepts normalized values (0.0-1.0) and
 * converts them to the appropriate PWM range (0-255 for Arduino).
 */
class PWMOutput : public IOutput {
public:
	/**
	 * Configures a pin as a PWM output.
	 *
	 * @param hal The Hardware Abstraction Layer (HAL).
	 * @param pin The pin number.
	 */
	PWMOutput(IHAL &hal, int pin);

	float getValue() override;
	void setValue(float value) override;

private:
	IHAL &m_hal;
	int m_pin;
	float m_value;
};

#endif // PWM_OUTPUT_H
