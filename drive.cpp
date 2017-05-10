#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
int previousError = 0

void lineDrive(const int error) {
	double scaledSpeed = (double) error * getScale(error, previousError);
	previousError = getScale(error, previousError);
	//int leftMotorSpeed;
	//int rightMotorSpeed;
	//if (scaledSpeed > 0) {
	//	std::cout << "Scale speed > 0";
	//	leftMotorSpeed = (int) scaledSpeed;
	//	rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	//}
	//else if (scaledSpeed < 0) {
	//	std::cout << "Scale speed < 0";
	//	leftMotorSpeed = constants::vehicle::STABLE_SPEED;
	//	rightMotorSpeed = (int) scaledSpeed;
	//}
	//else {
	//	leftMotorSpeed = constants::vehicle::STABLE_SPEED;
	//	rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	//}
	turn(Math.min(254-constants::vehicle::STABLE_SPEED,(constants::vehicle::STABLE_SPEED + (int) scaledSpeed)));
	//std::cout << "Setting left motor speed";
	//set_motor(constants::vehicle::parts::LEFT_MOTOR, leftMotorSpeed);
	//std::cout << "Setting right motor speed";
	//set_motor(constants::vehicle::parts::RIGHT_MOTOR, rightMotorSpeed);
	//std::cout << "Sleeping";
	//sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MICROSECONDS);
	//std::cout << "Stopping motors";
	//set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
	//set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	//std::cout << "Sleeping";
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
