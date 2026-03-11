#include <IHAL.h>
#include <gmock/gmock.h>

class MockHAL : public IHAL {
public:
	MOCK_METHOD(int, analogRead, (int pin), (override));
	MOCK_METHOD(void, analogWrite, (int pin, int value), (override));
	MOCK_METHOD(void, delay, (unsigned long ms), (override));
	MOCK_METHOD(unsigned long, millis, (), (override));
	MOCK_METHOD(int, getMaxAnalogReadQuant, (), (const, override));
	MOCK_METHOD(int, getMaxAnalogWriteQuant, (), (const, override));
};
