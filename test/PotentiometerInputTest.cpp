#include <IHAL.h>
#include <PotentiometerInput.h>
#include <gmock/gmock.h>

using ::testing::Return;

class MockHAL : public IHAL {
public:
	static const int MAX_ANALOG_READ_QUANT = 1023;
	MOCK_METHOD(int, analogRead, (int pin), (override));
	MOCK_METHOD(void, analogWrite, (int pin, int value), (override));
	MOCK_METHOD(void, delay, (unsigned long ms), (override));
	MOCK_METHOD(unsigned long, millis, (), (override));
	MOCK_METHOD(int, getMaxAnalogReadQuant, (), (const, override));
};

class PotentiometerInputTest : public testing::Test {
protected:
	int pin = 0;
	MockHAL hal;
	PotentiometerInput input = PotentiometerInput(hal, pin);
	float maxError = (float)1 / MockHAL::MAX_ANALOG_READ_QUANT;
};

TEST_F(PotentiometerInputTest, ReadsZero) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant())
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT));

	EXPECT_CALL(hal, analogRead(pin)).WillOnce(Return(0));

	EXPECT_NEAR(input.getValue(), 0, maxError);
}

TEST_F(PotentiometerInputTest, ReadsOne) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant())
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT));

	EXPECT_CALL(hal, analogRead(pin))
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT));

	EXPECT_NEAR(input.getValue(), 1, maxError);
}

TEST_F(PotentiometerInputTest, ReadsIntermediateValue) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant())
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT));

	EXPECT_CALL(hal, analogRead(pin))
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT * 0.5));

	EXPECT_NEAR(input.getValue(), 0.5, maxError);
}

TEST_F(PotentiometerInputTest, UpdatesCorrectly) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant())
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT))
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT));

	EXPECT_CALL(hal, analogRead(pin))
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT * 0.25))
		.WillOnce(Return(MockHAL::MAX_ANALOG_READ_QUANT * 0.75));

	EXPECT_NEAR(input.getValue(), 0.25, maxError);
	EXPECT_NEAR(input.getValue(), 0.75, maxError);
}
