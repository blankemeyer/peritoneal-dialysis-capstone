#include <AdafruitDisplay.h>
#include <stdint.h>

// Instantiate Adafruit driver using hardware SPI.
AdafruitDisplay::AdafruitDisplay(int csPin, int dcPin)
		// TODO(will): should we assert that 'csPin' and 'dcPin' are in range for
		//             'int8_t'?
		: m_driver{
				static_cast<int8_t>(csPin), static_cast<int8_t>(dcPin), /*rst=*/-1
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
	return DEFAULT_TEXT_WIDTH;
}

unsigned AdafruitDisplay::getTextHeight() const {
	return DEFAULT_TEXT_HEIGHT;
}

void AdafruitDisplay::clearScreen(Color color) {
	m_driver.fillScreen(encodeColor(color));
}

void AdafruitDisplay::drawText(Point topLeft, Color color, const char *string) {
	m_driver.setCursor(
		static_cast<int16_t>(topLeft.x), static_cast<int16_t>(topLeft.y)
	);
	m_driver.setTextColor(encodeColor(color));
	m_driver.print(string);
}

AdafruitDisplay::Color565 AdafruitDisplay::encodeColor(Color color) {
	switch (color) {
	case Color::Black:
		return 0;
	case Color::White:
		return UINT16_MAX;
	default:
		// There are no other colors.
		__builtin_unreachable();
	}
}
