#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0;

void lineDrive(const int error) {
	if (isRedPatch()) {
		stop();
		printf("Found a red patch");
	}
	double scaledSpeed = (double) error * getScale(error, previousError);
	previousError = getScale(error, previousError);
	turn(Math.min(254 - constants::vehicle::STABLE_SPEED, (constants::vehicle::STABLE_SPEED + (int) scaledSpeed)));
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	for(int counter = 0; counter < 99999; counter += 1) {
		const int error = getError();
		printf("Error: %i\n", error);
		lineDrive(error);
	}
}
