//driveForward is a function, given a speed will drive the robot forward

#include "driveFunctions.h"

void driveForward(int speed) { //takes a speed between the values -254 and 254
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, -speed);
	driveSleep();
	stopDriving();
}

void driveBackward(int speed) {
	driveForward(-speed);
}

void turnRight(int speed) {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, constants::vehicle::STABLE_SPEED);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, -speed);
	driveSleep();
	stopDriving();
}

void turnLeft(int speed) {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, -constants::vehicle::STABLE_SPEED);
	driveSleep();
	stopDriving();
}

void turn(int speed) {
	if (speed > 0) {
		turnRight(speed);
	}
	else {
		turnLeft(-speed);
	}
}

void stopDriving() {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
}

void driveSleep() {
	sleep1(constants::vehicle::SLEEP_TIME_SECONDS, constants::vehicle::SLEEP_TIME_MICROSECONDS);
}