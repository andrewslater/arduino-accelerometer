#include "Arduino.h"
#include "Accelerometer.h"

Accelerometer::Accelerometer(int xInputPin, int yInputPin, int zInputPin) {
	analogReference(EXTERNAL);

	x = y = z = 0;
	deltaX = deltaY = deltaZ = 0;	
	sampleSize = DEFAULT_SAMPLE_SIZE;

	xPin = xInputPin;
	yPin = yInputPin;
	zPin = zInputPin;
}

int Accelerometer::getX() {
	return x;
}

int Accelerometer::getY() {
	return y;
}

int Accelerometer::getZ() {
	return z;
}

int Accelerometer::getDeltaX() {
	return deltaX;
}

int Accelerometer::getDeltaY() {
	return deltaY;
}

int Accelerometer::getDeltaZ() {
	return deltaZ;
}

int Accelerometer::getAbsDeltaX() {
	return abs(getDeltaX());
}

int Accelerometer::getAbsDeltaY() {
	return abs(getDeltaY());
}

int Accelerometer::getAbsDeltaZ() {
	return abs(getDeltaZ());
}

void Accelerometer::setSampleSize(int newSampleSize) {
	if (newSampleSize < 1) {
		Serial.print("Invalid accelerometer sample size: ");
		Serial.println(newSampleSize);
		return;
	}

	sampleSize = newSampleSize;
}

void Accelerometer::refresh() {
	if (!pinsAreValid()) {
		Serial.println("WARNING: Accelerometer pins are not configured to valid digital pins");
		return;
	}

	int newX = readAxis(xPin);
	int newY = readAxis(yPin);
	int newZ = readAxis(zPin);

	deltaX = newX - x;
	deltaY = newY - y;
	deltaZ = newZ - z;

	x = newX;
	y = newY;
	z = newZ;
}

void Accelerometer::debug() {
	if (!pinsAreValid()) {
		Serial.println("WARNING: Accelerometer pins are not configured to valid digital pins");
		return;
	}

	debugAttitude("Accelerometer orientation: ", x, y ,z);
}

void Accelerometer::debugAttitude(String desc, int x, int y, int z) {
    Serial.print(desc);
    Serial.print(" X: ");
    Serial.print(x);
    Serial.print(" Y: ");
    Serial.print(y);
    Serial.print(" Z: ");
    Serial.println(z);  
}

//
// Private Members
//
int Accelerometer::readAxis(int axisPin) {
	long reading = 0;
	analogRead(axisPin);
	delay(1);
	for (int i = 0; i < sampleSize; i++) {
		reading += analogRead(axisPin);	
	}
	return reading / sampleSize;
}

bool Accelerometer::pinsAreValid() {
	return (xPin != UNKNOWN_PIN && yPin != UNKNOWN_PIN && zPin != UNKNOWN_PIN);
}

