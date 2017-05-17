#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0;

void lineDrive(const int error, const int previousError, const int totalErrorExperienced) {
	if (isRedPatch()) {
		printf("Found a red patch");
		stopDriving();
	}
	//TODO: test to confirm setting the speed directly to the PID signal works as expected. It seemed to be earlier.
	double scaledSpeed = getPIDSignal(error, previousError, totalErrorExperienced);
	scaledSpeed > constants::vehicle::MAX_SPEED ? scaledSpeed = constants::vehicle::MAX_SPEED
												: scaledSpeed = scaledSpeed;
	if (error < 0) {
		turnRight(scaledSpeed);
	}
	else {
		turnLeft(scaledSpeed);
	}
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	openGate();
	//Remember this is taking a picture
	int previousError = getError();
	int totalExperiencedError = previousError;
	//A red patch signifies the end of the line driving. Using the isRedPatch method before the getError method is a
	// slight hack as a picture isn't taken for the red patch to evaluate. It still works as all values in the picture
	// are initialised to 0, and the ratio of red pixels to non red pixels stays low.
	while (isRedPatch() == false) {
		const int error = getError();
		totalExperiencedError += error;
		printf("Error: %i\n", error);
		lineDrive(error, previousError, totalExperiencedError);
		previousError = error;
	}
}
