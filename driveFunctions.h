#ifndef C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
#define C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
#include "E101.h"
#include "config.h"

//functions in cpp file
void driveForward(double time, int speed);

void driveBackward(double time, int speed);

void turnLeft(double time, int speed);

void turnRight(double time, int speed);

void stopDriving();

void driveSleep();

#endif //C_MINUS_MINUS_AVC_DRIVEFUNCTIONS_H
