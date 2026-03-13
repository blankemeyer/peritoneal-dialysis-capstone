#include <MockHAL.h>
#include <PotentiometerInput.h>
#include <gmock/gmock.h>

using ::testing::Return;

class PotentiometerInputTest : public testing::Test {
protected:
	int pin = 0;
	MockHAL hal;
	PotentiometerInput input = PotentiometerInput(hal, pin);
};

TEST_F(PotentiometerInputTest, ReadsZero) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant()).WillOnce(Return(1023));

	EXPECT_CALL(hal, analogRead(pin)).WillOnce(Return(0));

	EXPECT_FLOAT_EQ(input.getValue(), 0);
}

TEST_F(PotentiometerInputTest, ReadsOne) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant()).WillOnce(Return(1023));

	EXPECT_CALL(hal, analogRead(pin)).WillOnce(Return(1023));

	EXPECT_FLOAT_EQ(input.getValue(), 1);
}

TEST_F(PotentiometerInputTest, ReadsIntermediateValue) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant()).WillOnce(Return(1023));

	EXPECT_CALL(hal, analogRead(pin)).WillOnce(Return(512));

	EXPECT_FLOAT_EQ(input.getValue(), (float)512 / 1023);
}

TEST_F(PotentiometerInputTest, UpdatesCorrectly) {
	EXPECT_CALL(hal, getMaxAnalogReadQuant())
		.WillOnce(Return(1023))
		.WillOnce(Return(1023));

	EXPECT_CALL(hal, analogRead(pin)).WillOnce(Return(256)).WillOnce(Return(768));

	EXPECT_FLOAT_EQ(input.getValue(), (float)256 / 1023);
	EXPECT_FLOAT_EQ(input.getValue(), (float)768 / 1023);
}
