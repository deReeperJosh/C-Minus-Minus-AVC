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
	double derivativeSignal = (currentError - previousError / 0.1) * kd;
	double finalSignal = proportionalSignal + derivativeSignal;
	return finalSignal;
}
