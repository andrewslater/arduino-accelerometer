#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "Arduino.h"

class Accelerometer {

	public:
		Accelerometer(int xInputPin = UNKNOWN_PIN, int yInputPin = UNKNOWN_PIN, int zInputPin = UNKNOWN_PIN);
		int getX();
		int getY();
		int getZ();
		int getDeltaX();
		int getDeltaY();
		int getDeltaZ();
		int getAbsDeltaX();
		int getAbsDeltaY();
		int getAbsDeltaZ();

		void setSampleSize(int newSampleSize);
		void refresh();
		void debug();
		void debugAttitude(String desc, int x, int y, int z);

	private:
		static const int UNKNOWN_PIN = -1;
		static const int DEFAULT_SAMPLE_SIZE = 20;

		int xPin;
		int yPin;
		int zPin;

		int x;
		int y;
		int z;

		int deltaX;
		int deltaY;
		int deltaZ;

		int sampleSize;

		int readAxis(int axisPin);
		bool pinsAreValid();
};

#endif