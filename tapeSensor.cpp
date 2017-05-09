#include "tapeSensor.h"

using namespace std;

/**
 * @note Fills the argument pixelValues with the whiteness values for the middle row of a taken picture
 * @param pixelValues Pass an vector object, the function works on this parameter by reference.
 * @param size Pass the absolute size that the vector should be.
 * */
void getPixelValues(std::vector<int> &pixelValues, const int COLUMNS) {
	//take a picture of the surface
	take_picture();
	//fill the pixelValues vector object to the given size using the middle
	for (int counter = 0; counter < COLUMNS; counter += 1) {
		//calculates the whiteness value of a pixel by taking a pixel halfway down the image at index counter
		int pixelValue = get_pixel((constants::picture::ROWS / 2), counter, 3);
		//add the calculated whiteness value to the end of the vector object
		pixelValues.push_back(pixelValue);
	}
}

/**
 * @note Fills the argument pixelStatesValues with true or false according to wether the corresponding pixelValue
 * evaluates to white or black
 * @param pixelStates Pass a vector object of type boolean; it will be worked on by reference. The function fills with
 * true if the value in pixelValues with the corresponding index evaluates to white, otherwise the function fills with
 * false.
 * @param size Pass the absolute size that the pixelStates vector should be.
 * @param pixelValues Pass a vector object of pixelValues between 0 and 255.
 */
void calculatePixelStates(std::vector<bool> &pixelStateValues, const int size, std::vector<int> pixelValues) {
	//for every pixel value, calculate if it is white or not
	for (int counter = 0; counter < pixelValues.size(); counter += 1) {
		//store the pixel whiteness value at this index in the pixelValues vector in the variable 'pixelValue'
		int pixelValue = pixelValues.at(counter);
		//if the pixel value is greater than the maximum specified value of black, it is therefore a white pixel
		if (pixelValue > constants::picture::MAXIMUM_BLACK_VALUE) {
			//add the value true to the end of the pixelValues object, signifying a white pixel
			pixelValues.push_back(true);
		}
		//otherwise, we know it is a black pixel
		else {
			//add the value false to the end of the pixelValues object, signifying a black pixel
			pixelValues.push_back(false);
		}
	}
}

/**
 * @note overloaded getError. Should only be called by the getError() method with no parameters call-signature
 * @param pixelStates Pass a vector object representing if a pixel evaluated to white (true) or black (false).
 * @return Returns an signed integer value for the calculated error. A negative value shows that there are a higher
 * weight of white pixels to the left, a positive value implies the same, except to the right.
 */
int getError(std::vector<bool> pixelStates) {
	//variable to hold the total error value. A negative value will show that the robot needs to turn left, and a
	//positive value shows that it needs to turn right
	int totalError = 0;
	int totalWhitePixels = 0;
	//calculate the total error of the white code
	for (int counter = 0; counter < pixelStates.size(); counter += 1) {
		if (pixelStates.at(counter)) {
			totalWhitePixels++;
			const int pixelWeight = counter - (pixelStates.size() / 2);
			totalError += pixelWeight;
			totalError /= totalWhitePixels;
		}
	}
	return totalError /= totalWhitePixels;
}

/**
 * @return Returns an signed integer value for the calculated error (currently for all pixels in the row). A negative
 * value shows that there are a higher weight of white pixels to the left, a positive value implies the same, except
 * to the right.
 */
int getError() {
	//as getPixelValues works on a vector object by reference, we need to declare it before calling it
	std::vector<int> pixelWhitenessValues;
	getPixelValues(pixelWhitenessValues, constants::picture::COLUMNS);
	//as pixelStateValues works on a vector object by reference, we need to declare it before calling it
	std::vector<bool> pixelStateValues;
	//only now is the pixelStateValues set, and we can calculate the error
	calculatePixelStates(pixelStateValues, constants::picture::COLUMNS, pixelWhitenessValues);
	return getError(pixelStateValues);
}
