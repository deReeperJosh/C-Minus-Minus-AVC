#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0;

void lineDrive(const int error) {
	if (isRedPatch()) {
		printf("Found a red patch");
		stopDriving();
	}
	//double scaledSpeed = (double) error * getScale(error, previousError);
	//previousError = getScale(error, previousError);
	//turn(Math.min(254 - constants::vehicle::STABLE_SPEED, (constants::vehicle::STABLE_SPEED + (int) scaledSpeed)));
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	openGate();
	//A red patch signifies the end of the line driving. Using the isRedPatch method before the getError method is a
	// slight hack as a picture isn't taken for the red patch to evaluate. It still works as all values in the picture
	// are initialised to 0, and the ratio of red pixels to non red pixels stays low.
	while(isRedPatch() == false) {
		const int error = getError();
		printf("Error: %i\n", error);
		lineDrive(error);
	}
}
