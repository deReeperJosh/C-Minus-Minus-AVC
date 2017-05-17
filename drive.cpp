#include "drive.h"

/**
 * @note UNTESTED (it's not gonna work). Drives the robot forwards considering the error value in line follow mode
 * @param error Pass a signed int for the error value
 */
void lineDrive(const int error) {
	if(isRedPatch()){
		stop();
		printf("Found a red patch");
	}
	double scaledSpeed = (double) error * constants::PID::PROPORTIONAL_SCALE;
	int leftMotorSpeed;
	int rightMotorSpeed;
	if (scaledSpeed > 0) {
		std::cout << "Scale speed > 0\n";
		leftMotorSpeed = (int) scaledSpeed;
		rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	}
	else if (scaledSpeed < 0) {
		std::cout << "Scale speed < 0\n";
		leftMotorSpeed = constants::vehicle::STABLE_SPEED;
		rightMotorSpeed = (int) scaledSpeed;
	}
	else {
		leftMotorSpeed = constants::vehicle::STABLE_SPEED;
		rightMotorSpeed = constants::vehicle::STABLE_SPEED;
	}
	std::cout << "Setting left motor speed\n";
	set_motor(constants::vehicle::parts::LEFT_MOTOR, leftMotorSpeed);
	std::cout << "Setting right motor speed\n";
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, rightMotorSpeed);
	std::cout << "Sleeping\n";
	sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MICROSECONDS);
	std::cout << "Stopping motors\n";
	set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	std::cout << "Sleeping\n";
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
