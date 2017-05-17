//driveForward is a function, given a speed will drive the robot forward

#include "driveFunctions.h"

void driveForward(int speed) { //takes a speed between the values -254 and 254
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, (-constants::vehicle::STABLE_SPEED) - speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, (-constants::vehicle::STABLE_SPEED) - speed);
	driveSleep();
	stopDriving();
}

void driveBackward(int speed) {
	driveForward(-speed);
}

void turnRight(int speed) {
	speed = certifySpeedIsSafe(speed);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, constants::vehicle::STABLE_SPEED);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, (constants::vehicle::STABLE_SPEED) + speed);
	driveSleep();
	stopDriving();
}

void turnLeft(int speed) {
	speed = certifySpeedIsSafe(speed);
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, (constants::vehicle::STABLE_SPEED) + speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, constants::vehicle::STABLE_SPEED);
	driveSleep();
	stopDriving();
}

int certifySpeedIsSafe(const int speed) {
	//certify that the scaled speed isn't higher than the maximum possible speed
	if (speed > constants::vehicle::MAX_SPEED) {
		speed = constants::vehicle::MAX_SPEED;
	}
	return speed;
}

void stopDriving() {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
}

void driveSleep() {
	sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MICROSECONDS);
}
