#include <AdafruitTFTDriver.h>
#include <Arduino.h>
#include <ArduinoHAL.h>
#include <CatheterController.h>
#include <TFTDisplay.h>

enum {
	INPUT_PIN_1 = A0,
	INPUT_PIN_2 = A2,
	OUTPUT_PIN_1 = 5,
	OUTPUT_PIN_2 = 6,
	DISPLAY_CS_PIN = 10,
	DISPLAY_DC_PIN = 8,
	BAUD_RATE = 9600,
	DELAY_MS = 100,
};

ArduinoHAL hal(BAUD_RATE);
AdafruitTFTDriver tftDriver(DISPLAY_CS_PIN, DISPLAY_DC_PIN);
TFTDisplay display(tftDriver);
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
