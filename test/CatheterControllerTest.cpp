#include <CatheterController.h>

#include <gmock/gmock.h>

using ::testing::Return;

class MockChannel {
public:
    MOCK_METHOD(void, update, ());
    MOCK_METHOD(float, getOutputValue, ());
};

class MockDisplay {
public:
    MOCK_METHOD(void, initialize, ());
};

class CatheterControllerTest : public testing::Test {
protected:
    CatheterControllerTest() : m_controller{m_chan1, m_chan2, m_display} {}

    MockChannel m_chan1;
    MockChannel m_chan2;
    MockDisplay m_display;
    CatheterController m_controller;
};

TEST_F(CatheterControllerTest, UpdatesPeripherals) {
    EXPECT_CALL(m_chan1, update()).Times(1);
    EXPECT_CALL(m_chan2, update()).Times(1);
    EXPECT_CALL(m_chan1, getOutputValue()).WillOnce(Return(.123f));
    EXPECT_CALL(m_chan2, getOutputValue()).WillOnce(Return(.928f));
    EXPECT_CALL(m_display, update(.123f, .928f)).Times(1);

    m_controller.update();
}
