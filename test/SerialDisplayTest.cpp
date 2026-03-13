#include <MockHAL.h>
#include <SerialDisplay.h>

class SerialDisplayTest : public testing::Test {
protected:
	MockHAL hal;
	SerialDisplay display = SerialDisplay(hal);
};

TEST_F(SerialDisplayTest, InitializesSerial) {
	EXPECT_CALL(hal, beginSerial());

	display.initialize();
}

TEST_F(SerialDisplayTest, DisplaysZeros) {
	auto expected =
		"Wire 1 Power Level:\t0%\n"
		"Wire 2 Power Level:\t0%\n";

	EXPECT_CALL(hal, println(expected));

	display.update(0, 0);
}

TEST_F(SerialDisplayTest, DisplaysHundreds) {
	auto expected =
		"Wire 1 Power Level:\t100%\n"
		"Wire 2 Power Level:\t100%\n";

	EXPECT_CALL(hal, println(expected));

	display.update(1, 1);
}

TEST_F(SerialDisplayTest, DisplaysMixedValues) {
	auto expected =
		"Wire 1 Power Level:\t25%\n"
		"Wire 2 Power Level:\t75%\n";

	EXPECT_CALL(hal, println(expected));

	display.update(0.25, 0.75);
}

TEST_F(SerialDisplayTest, RoundsToTheNearestPercent) {
	auto expected =
		"Wire 1 Power Level:\t44%\n"
		"Wire 2 Power Level:\t56%\n";

	EXPECT_CALL(hal, println(expected));

	display.update(0.4444, 0.5555);
}
