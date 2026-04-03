#include <Arduino.h>
#include <ArduinoHAL.h>
#include <CatheterController.h>
#include <SerialDisplay.h>

enum {
	INPUT_PIN_1 = A0,
	INPUT_PIN_2 = A2,
	OUTPUT_PIN_1 = 10,
	OUTPUT_PIN_2 = 11,
	BAUD_RATE = 9600,
	DELAY_MS = 100,
};

ArduinoHAL hal(BAUD_RATE);
SerialDisplay display(hal);
CatheterController controller(
	hal, INPUT_PIN_1, OUTPUT_PIN_1, INPUT_PIN_2, OUTPUT_PIN_2, display
);

void setup() {
	display.initialize();
}

void loop() {
	controller.update();
	hal.delayMs(DELAY_MS);
}
