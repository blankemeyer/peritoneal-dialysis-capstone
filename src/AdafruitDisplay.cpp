#include <AdafruitDisplay.h>
#include <Adafruit_ST7735.h>
#include <stdint.h>

// <https://learn.adafruit.com/adafruit-mini-tft-0-dot-96-inch-180x60-breakout/wiring-test>
static constexpr uint8_t DISPLAY_REVISION{INITR_MINI160x80_PLUGIN};

// Instantiate Adafruit driver using hardware SPI.

AdafruitDisplay::AdafruitDisplay(int csPin, int dcPin)
		// TODO: should we assert that 'csPin' and 'dcPin' are in range for
		// 'int8_t'?
		: m_driver{
				static_cast<int8_t>(csPin), static_cast<int8_t>(dcPin), /*rstPin=*/-1
			} {}

void AdafruitDisplay::initializeDriver() {
	m_driver.initR(DISPLAY_REVISION);
}

unsigned AdafruitDisplay::getWidth() const {
	return m_driver.width();
}

unsigned AdafruitDisplay::getHeight() const {
	return m_driver.height();
}

unsigned AdafruitDisplay::getTextWidth() const {
	return DEFAULT_TEXT_HEIGHT;
}

unsigned AdafruitDisplay::getTextHeight() const {
	return DEFAULT_TEXT_WIDTH;
}

void AdafruitDisplay::clearScreen(Color color) {
	m_driver.fillScreen(encodeColor(color));
}

void AdafruitDisplay::drawText(Point topLeft, Color color, const char *string) {
	m_driver.setCursor(topLeft.x, topLeft.y);
	m_driver.setTextColor(encodeColor(color));
	m_driver.print(string);
}

AdafruitDisplay::Color565 AdafruitDisplay::encodeColor(Color color) {
	switch (color) {
	case Color::Black:
		return 0;
	case Color::White:
		return UINT16_MAX;
	}
}
