#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
void lineDrive(const int error) {
	double scaledSpeed = (double) error * constants::PID::PROPORTIONAL_SCALE;
	int leftMotorSpeed;
	int rightMotorSpeed;
	if (scaledSpeed > 0) {
		leftMotorSpeed = (int) scaledSpeed;
		rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	}
	else if (scaledSpeed < 0) {
		leftMotorSpeed = constants::vehicle::STABLE_SPEED;
		rightMotorSpeed = (int) scaledSpeed;
	}
	else {
		leftMotorSpeed = constants::vehicle::STABLE_SPEED;
		rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	}
	set_motor(constants::vehicle::parts::LEFT_MOTOR, leftMotorSpeed);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, rightMotorSpeed);
	sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MILLISECONDS);
}

/**
 * @note Starts the robots drive routine
 */
void drive() {
	while(true){
		lineDrive(getError());
	}
}