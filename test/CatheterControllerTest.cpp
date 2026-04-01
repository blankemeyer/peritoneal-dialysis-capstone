#include <CatheterController.h>
#include <IDisplay.h>
#include <IHAL.h>
#include <MockHAL.h>
#include <gmock/gmock.h>

using ::testing::FloatEq;
using ::testing::Return;

class MockDisplay : public IDisplay {
public:
	MOCK_METHOD(void, initialize, (), (override));
	MOCK_METHOD(void, update, (float, float), (override));
};

class CatheterControllerTest : public testing::Test {
protected:
	static constexpr int INPUT_1_PIN{0};
	static constexpr int OUTPUT_1_PIN{1};
	static constexpr int INPUT_2_PIN{2};
	static constexpr int OUTPUT_2_PIN{3};

	MockHAL m_hal;
	MockDisplay m_display;
	CatheterController m_controller = CatheterController(
		m_hal, INPUT_1_PIN, OUTPUT_1_PIN, INPUT_2_PIN, OUTPUT_2_PIN, m_display
	);
};

TEST_F(CatheterControllerTest, UpdatesWithArduinoQuantsAndMinInputs) {
	EXPECT_CALL(m_hal, getMaxAnalogReadQuant()).WillRepeatedly(Return(1023));
	EXPECT_CALL(m_hal, getMaxAnalogWriteQuant()).WillRepeatedly(Return(255));
	EXPECT_CALL(m_hal, analogRead(INPUT_1_PIN)).WillOnce(Return(0));
	EXPECT_CALL(m_hal, analogRead(INPUT_2_PIN)).WillOnce(Return(0));
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_1_PIN, 0)).Times(1);
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_2_PIN, 0)).Times(1);
	EXPECT_CALL(m_display, update(0.f, 0.f)).Times(1);

	m_controller.update();
}

TEST_F(CatheterControllerTest, UpdatesWithArduinoQuantsAndMaxInputs) {
	EXPECT_CALL(m_hal, getMaxAnalogReadQuant()).WillRepeatedly(Return(1023));
	EXPECT_CALL(m_hal, getMaxAnalogWriteQuant()).WillRepeatedly(Return(255));
	EXPECT_CALL(m_hal, analogRead(INPUT_1_PIN)).WillOnce(Return(1023));
	EXPECT_CALL(m_hal, analogRead(INPUT_2_PIN)).WillOnce(Return(1023));
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_1_PIN, 255)).Times(1);
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_2_PIN, 255)).Times(1);
	EXPECT_CALL(m_display, update(1.f, 1.f)).Times(1);

	m_controller.update();
}

TEST_F(CatheterControllerTest, UpdatesWithArduinoQuantsAndDifferentInputs) {
	EXPECT_CALL(m_hal, getMaxAnalogReadQuant()).WillRepeatedly(Return(1023));
	EXPECT_CALL(m_hal, getMaxAnalogWriteQuant()).WillRepeatedly(Return(255));
	EXPECT_CALL(m_hal, analogRead(INPUT_1_PIN)).WillOnce(Return(314));
	EXPECT_CALL(m_hal, analogRead(INPUT_2_PIN)).WillOnce(Return(777));
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_1_PIN, 78)).Times(1);
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_2_PIN, 193)).Times(1);
	EXPECT_CALL(m_display, update(FloatEq(.30588235f), FloatEq(.75686275f)))
		.Times(1);

	m_controller.update();
}

TEST_F(
	CatheterControllerTest, UpdatesTwiceWithArduinoQuantsAndDifferentInputs
) {
	EXPECT_CALL(m_hal, getMaxAnalogReadQuant()).WillRepeatedly(Return(1023));
	EXPECT_CALL(m_hal, getMaxAnalogWriteQuant()).WillRepeatedly(Return(255));
	EXPECT_CALL(m_hal, analogRead(INPUT_1_PIN)).WillOnce(Return(256));
	EXPECT_CALL(m_hal, analogRead(INPUT_2_PIN)).WillOnce(Return(614));
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_1_PIN, 63)).Times(1);
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_2_PIN, 153)).Times(1);
	EXPECT_CALL(m_display, update(FloatEq(.24705882f), FloatEq(.6f))).Times(1);

	m_controller.update();

	EXPECT_CALL(m_hal, getMaxAnalogReadQuant()).WillRepeatedly(Return(1023));
	EXPECT_CALL(m_hal, getMaxAnalogWriteQuant()).WillRepeatedly(Return(255));
	EXPECT_CALL(m_hal, analogRead(INPUT_1_PIN)).WillOnce(Return(86));
	EXPECT_CALL(m_hal, analogRead(INPUT_2_PIN)).WillOnce(Return(1000));
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_1_PIN, 21)).Times(1);
	EXPECT_CALL(m_hal, analogWrite(OUTPUT_2_PIN, 249)).Times(1);
	EXPECT_CALL(m_display, update(FloatEq(.082352941f), FloatEq(.97647059f)))
		.Times(1);

	m_controller.update();
}
