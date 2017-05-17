#include "pid.h"

double calculateProportionalSignal(const int error) {
	double proportionalSignal = error * constants::PID::PROPORTIONAL_CONSTANT;
	return proportionalSignal;
}

double calculateDerivativeSignal(const int error, const int previousError) {
	double derivativeSignal = (error - previousError) * constants::PID::DERIVATIVE_CONSTANT;
	return derivativeSignal;
}

double calculateIntegralSignal(const int totalErrorExperienced) {
	double integralSignal = totalErrorExperienced * constants::PID::INTEGRAL_CONSTANT;
	return integralSignal;
}

int getPIDSignal(const int error, const int previousError, const int totalErrorExperienced) {
	double finalSignal = calculateProportionalSignal(error) + calculateDerivativeSignal(error, previousError)
						 + calculateIntegralSignal(totalErrorExperienced);
	return (int) finalSignal;
}
