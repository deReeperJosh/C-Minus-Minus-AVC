#ifndef C_MINUS_MINUS_AVC_DRIVE_H
#define C_MINUS_MINUS_AVC_DRIVE_H

#include "iostream"
#include "E101.h"
#include "config.h"
#include "tapeSensor.h"
#include "pid.h"
#include "serverCommunication.h"
#include "driveFunctions.h"

void drive();

void lineDrive(const int error);

#endif //C_MINUS_MINUS_AVC_DRIVE_H
