#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0

void lineDrive(const int error) {
	double scaledSpeed = (double) error * getScale(error, previousError);
		previousError = getScale(error, previousError);
	turn(Math.min(254-constants::vehicle::STABLE_SPEED,(constants::vehicle::STABLE_SPEED + (int) scaledSpeed)));
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	while (true) {
		const int error = getError();
		printf("Error: %i\n", error);
		lineDrive(error);
	}
}
