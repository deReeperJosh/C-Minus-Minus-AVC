#ifndef C_MINUS_MINUS_AVC_PID_H
#define C_MINUS_MINUS_AVC_PID_H


#include "E101.h"
#include "config.h"

int getPIDSignal(const int error, const int previousError, const int totalErrorExperienced);

#endif //C_MINUS_MINUS_AVC_PID_H
