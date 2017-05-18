//driveForward is a function, given a speed will drive the robot forward

#include "driveFunctions.h"

int certifySpeedIsSafe(int speed) {
	//certify that the scaled speed isn't higher than the maximum possible speed
	if (speed > constants::vehicle::MAX_SPEED) {
		speed = constants::vehicle::MAX_SPEED;
	}
	return speed;
}

void driveForward(int speed) { //takes a speed between the values -254 and 254
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, (constants::vehicle::STABLE_SPEED) + speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, (constants::vehicle::STABLE_SPEED) + speed);
	driveSleep();
	stopDriving();
}

void driveBackward(int speed) {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, (-constants::vehicle::REVERSE_SPEED) - speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, (-constants::vehicle::REVERSE_SPEED) - speed);
	driveSleep();
	stopDriving();
}

void turnRight(int speed) {
	speed = certifySpeedIsSafe(speed);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, constants::vehicle::STABLE_SPEED - speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, constants::vehicle::STABLE_SPEED + speed);
	driveSleep();
	stopDriving();
}

void turnLeft(int speed) {
	speed = certifySpeedIsSafe(speed);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, constants::vehicle::STABLE_SPEED + speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, constants::vehicle::STABLE_SPEED - speed);
	driveSleep();
	stopDriving();
}

void stopDriving() {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
}

void driveSleep() {
	sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MICROSECONDS);
}

/**
 * @note This function spins the robot in a direction specified by the argument direction until the robot is
 * back on track.
 * @param direction Use the constants defined in the config.h file
 */
void spinUntilOnTrack(const char direction) {
	//A variable to store a function which should control which direction the robot will turn
	auto turnFunction;
	if (direction == constants::vehicle::spin::DIRECTION_LEFT) {
		turnFunction = turnLeft;
	}
	else if (direction == constants::vehicle::spin::DIRECTION_RIGHT) {
		turnFunction = turnRight;
	}
	else {
		printf("ERROR. Wrong value: %c passed to function spinUntilOnTrack\n", direction);
		return;
	}
	int currentError;
	do {
		//Remember, this takes a picture
		currentError = getError();
		turnFunction(constants::vehicle::spin::TURN_SPEED);
	}
	//Keep turning while the error is outside the desired range
	while (currentError < constants::vehicle::spin::MINIMUM_WHITENESS_VALUE ||
		   currentError > constants::vehicle::spin::MAXIMUM_WHITENESS_VALUE);
	print("Back on track\n");
}