#include "pid.h"

/**
* Needs to get a previous error from a last error check
* for the derivative.
*/
double getScale(int error, int previousError) {
	//Proportional
	double kp = 0.5;
	double proportionalSignal = error * kp;

	//Derivative
	double kd = 5.0;
	//commented this for the moment as I'm not sure why it's here. Solomon
	// sleep1(0, 100000);
	//double derivativeSignal = (currentError - previousError / 0.1) * kd;
	//double finalSignal = proportionalSignal + derivativeSignal;
	//return finalSignal;
	return 0;
}

double calculateProportionalSignal(const int error) {
	double proportionalSignal = error * constants::PID::PROPORTIONAL_CONSTANT;
	return proportionalSignal;
}

double calculateDerivativeSignal(const int error, const int previousError) {
	double derivativeSignal = (error - previousError) * constants::PID::DERIVATIVE_CONSTANT;
	return derivativeSignal;
}

double calculateIntegralSignal(const int totalErrorExperienced){
	double integralSignal = totalErrorExperienced * constants::PID::INTEGRAL_CONSTANT;
	return integralSignal;
}

double getPIDSignal(const int error, const int previousError, const int totalErrorExperienced) {
	double finalSignal = calculateProportionalSignal(error) + calculateDerivativeSignal(error, previousError)
						 + calculateIntegralSignal(totalErrorExperienced);
	return finalSignal;
}
