#include <ArduinoHAL.h>

#include <Arduino.h>

#include <assert.h>

ArduinoHAL::ArduinoHAL(int serialBaud) : m_serialBaud{serialBaud} {}

// Analog I/O

AnalogValue ArduinoHAL::analogRead(int pin) {
	return ::analogRead(pin);
}

void ArduinoHAL::analogWrite(int pin, AnalogValue value) {
	assert(value <= MAX_ANALOG_WRITE_QUANT);
	::analogWrite(pin, value);
}

AnalogValue ArduinoHAL::getMaxAnalogReadQuant() const {
	return MAX_ANALOG_READ_QUANT;
}

AnalogValue ArduinoHAL::getMaxAnalogWriteQuant() const {
	return MAX_ANALOG_WRITE_QUANT;
}

// Digital I/O

DigitalValue ArduinoHAL::digitalRead(int pin) {
	return static_cast<DigitalValue>(::digitalRead(pin));
}

void ArduinoHAL::digitalWrite(int pin, DigitalValue value) {
	assert(value == LOW || value == HIGH);
	::digitalWrite(pin, value);
}

// Serial

void ArduinoHAL::beginSerial() {
	Serial.begin(m_serialBaud);
}

size_t ArduinoHAL::print(const char *s) {
	return Serial.print(s);
}

size_t ArduinoHAL::println(const char *s) {
	return Serial.println(s);
}

// Timing

void ArduinoHAL::delayMs(unsigned long durationMs) {
	::delay(durationMs);
}

unsigned long ArduinoHAL::getTimeMs() {
	return ::millis();
}
