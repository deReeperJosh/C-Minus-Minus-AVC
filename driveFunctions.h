#ifndef C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
#define C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
#include "E101.h"
#include "config.h"
#include "stdio.h"
#include "tapeSensor.h"

//functions in cpp file
void driveForward(int speed);

void driveBackward(int speed);

void turnLeft(int speed);

void turnRight(int speed);

void stopDriving();

void driveSleep();

void turn(int speed);

void spinUntilOnTrack(const char direction);

#endif //C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
