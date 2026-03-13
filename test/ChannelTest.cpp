#include <Channel.h>
#include <IInput.h>
#include <IOutput.h>
#include <gmock/gmock.h>

using ::testing::Return;

class MockInput : public IInput {
public:
	MOCK_METHOD(float, getValue, (), (override));
};

class MockOutput : public IOutput {
public:
	MOCK_METHOD(float, getValue, (), (override));
	MOCK_METHOD(void, setValue, (float value), (override));
};

class ChannelTest : public testing::Test {
protected:
	MockInput input;
	MockOutput output;
	Channel channel = Channel(input, output);
};

TEST_F(ChannelTest, TransmitsZero) {
	EXPECT_CALL(input, getValue()).WillOnce(Return(0));

	EXPECT_CALL(output, setValue(0)).Times(1);

	EXPECT_CALL(output, getValue()).WillOnce(Return(0));

	channel.update();
	EXPECT_FLOAT_EQ(channel.getOutputValue(), 0);
}

TEST_F(ChannelTest, TransmitsOne) {
	EXPECT_CALL(input, getValue()).WillOnce(Return(1));

	EXPECT_CALL(output, setValue(1)).Times(1);

	EXPECT_CALL(output, getValue()).WillOnce(Return(1));

	channel.update();
	EXPECT_FLOAT_EQ(channel.getOutputValue(), 1);
}

TEST_F(ChannelTest, TransmitsIntermediateValue) {
	EXPECT_CALL(input, getValue()).WillOnce(Return(0.75));

	EXPECT_CALL(output, setValue(0.75)).Times(1);

	EXPECT_CALL(output, getValue()).WillOnce(Return(0.75));

	channel.update();
	EXPECT_FLOAT_EQ(channel.getOutputValue(), 0.75);
}

TEST_F(ChannelTest, UpdatesWithInput) {
	EXPECT_CALL(input, getValue()).WillOnce(Return(0.25)).WillOnce(Return(0.75));

	EXPECT_CALL(output, setValue(0.25)).Times(1);
	EXPECT_CALL(output, setValue(0.75)).Times(1);

	EXPECT_CALL(output, getValue()).WillOnce(Return(0.25)).WillOnce(Return(0.75));

	channel.update();
	EXPECT_FLOAT_EQ(channel.getOutputValue(), 0.25);
	channel.update();
	EXPECT_FLOAT_EQ(channel.getOutputValue(), 0.75);
}
