#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
void lineDrive(const int error) {
	const int LEFT_MOTOR = 1;
	const int RIGHT_MOTOR = 2;
	const double SCALE = 2;
	const int STABLE_SPEED = 100;
	const int SLEEP_TIME_SECONDS = 0;
	const int SLEEP_TIME_MILLISECONDS = 50000;
	double scaledSpeed = (double) error * SCALE;
	int leftMotorSpeed;
	int rightMotorSpeed;
	if (scaledSpeed > 0) {
		leftMotorSpeed = (int) scaledSpeed;
		rightMotorSpeed = STABLE_SPEED;
	}
	else if (scaledSpeed < 0) {
		leftMotorSpeed = STABLE_SPEED;
		rightMotorSpeed = (int) scaledSpeed;
	}
	else {
		leftMotorSpeed = STABLE_SPEED;
		rightMotorSpeed = STABLE_SPEED;
	}
	set_motor(LEFT_MOTOR, leftMotorSpeed);
	set_motor(RIGHT_MOTOR, rightMotorSpeed);
	sleep1(SLEEP_TIME_SECONDS, SLEEP_TIME_MILLISECONDS);
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	while(true){
		lineDrive(getError());
	}
}