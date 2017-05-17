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
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, 0);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, -speed);
	driveSleep();
	stopDriving();
}

void turnLeft(int speed) {
	set_motor(constants::vehicle::parts::RIGHT_MOTOR, -speed);
	set_motor(constants::vehicle::parts::LEFT_MOTOR, 0);
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
