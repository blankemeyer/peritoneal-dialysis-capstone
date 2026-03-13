#include <IHAL.h>
#include <gmock/gmock.h>

class MockHAL : public IHAL {
public:
	MOCK_METHOD(AnalogValue, analogRead, (int pin), (override));
	MOCK_METHOD(void, analogWrite, (int pin, AnalogValue value), (override));
	MOCK_METHOD(AnalogValue, getMaxAnalogReadQuant, (), (const, override));
	MOCK_METHOD(AnalogValue, getMaxAnalogWriteQuant, (), (const, override));
	MOCK_METHOD(DigitalValue, digitalRead, (int pin), (override));
	MOCK_METHOD(void, digitalWrite, (int pin, DigitalValue value), (override));
	MOCK_METHOD(void, beginSerial, (), (override));
	MOCK_METHOD(size_t, print, (const char *s), (override));
	MOCK_METHOD(size_t, println, (const char *s), (override));
	MOCK_METHOD(void, delayMs, (unsigned long durationMs), (override));
	MOCK_METHOD(unsigned long, getTimeMs, (), (override));
};
