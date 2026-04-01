/**
 * @file PotentiometerInput.h
 */

#ifndef POTENTIOMETER_INPUT_H
#define POTENTIOMETER_INPUT_H

#include <IHAL.h>
#include <IInput.h>

/**
 * Potentiometer Input
 *
 * Implementation of `IInput`. Has a reference to the HAL and a pin number.
 * Reads an analog potentiometer and provides normalized values. Arduino
 * analog inputs range from 0-1023, which are normalized to 0.0-1.0.
 */
class PotentiometerInput : public IInput {
public:
	/**
	 * Configueres a pin as a potentiometer input.
	 *
	 * @param hal The Hardware Abstraction Layer (HAL).
	 * @param pin The pin number.
	 */
	PotentiometerInput(IHAL &hal, int pin);

	float getValue() override;

private:
	IHAL &m_hal;
	int m_pin;
};

#endif // POTENTIOMETER_INPUT_H
