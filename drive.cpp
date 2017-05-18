#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0;

void lineDrive(const int error, const int previousError, const int totalErrorExperienced) {
	int scaledSpeed = getPIDSignal(error, previousError, totalErrorExperienced);
	//certify that the scaled speed isn't negative
	if (scaledSpeed < 0) scaledSpeed *= -1;
	int offLineCount = 0;
	if (isBlackEverywhere()) {
		if (offLineCount > 5) {
			spinUntilOnTrack(constants::vehicle::spin::DIRECTION_RIGHT);
		}
		printf("Should reverse. Error: %d\n", error);
		driveBackward(constants::vehicle::STABLE_SPEED);
		offLineCount += 1;
	}
	else if(error == 0) {
		printf("Should be going forwards\n");
		driveForward(constants::vehicle::STABLE_SPEED * 1.5);
		offLineCount = 0;
	}
	else if (error < 0) {
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
