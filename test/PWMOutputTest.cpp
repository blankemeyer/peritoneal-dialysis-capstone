#include <MockHAL.h>
#include <PWMOutput.h>
#include <gmock/gmock.h>

using ::testing::Return;

class PWMOutputTest : public testing::Test {
protected:
	int pin = 0;
	MockHAL hal;
	PWMOutput output = PWMOutput(hal, pin);
};

TEST_F(PWMOutputTest, WritesZero) {
	EXPECT_CALL(hal, getMaxAnalogWriteQuant()).WillOnce(Return(255));

	EXPECT_CALL(hal, analogWrite(pin, 0));

	output.setValue(0);
	EXPECT_FLOAT_EQ(output.getValue(), 0);
}

TEST_F(PWMOutputTest, WritesOne) {
	EXPECT_CALL(hal, getMaxAnalogWriteQuant()).WillOnce(Return(255));

	EXPECT_CALL(hal, analogWrite(pin, 255));

	output.setValue(1);
	EXPECT_FLOAT_EQ(output.getValue(), 1);
}

TEST_F(PWMOutputTest, WritesIntermediateValue) {
	EXPECT_CALL(hal, getMaxAnalogWriteQuant()).WillOnce(Return(255));

	EXPECT_CALL(hal, analogWrite(pin, 127));

	output.setValue(0.5);
	EXPECT_FLOAT_EQ(output.getValue(), (float)127 / 255);
}

TEST_F(PWMOutputTest, UpdatesCorrectly) {
	EXPECT_CALL(hal, getMaxAnalogWriteQuant())
		.WillOnce(Return(255))
		.WillOnce(Return(255));

	EXPECT_CALL(hal, analogWrite(pin, 63));
	EXPECT_CALL(hal, analogWrite(pin, 191));

	output.setValue(0.25);
	EXPECT_FLOAT_EQ(output.getValue(), (float)63 / 255);

	output.setValue(0.75);
	EXPECT_FLOAT_EQ(output.getValue(), (float)191 / 255);
}
