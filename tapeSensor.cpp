#include "tapeSensor.h"

using namespace std;

/**
 * @note Takes a picture and finds and returns the whiteness values of each of the pixels in the centre row
 * @return A vector object of type int containing the pixel whiteness values (between 0 and 255) of the middle row
 * */
std::vector<int> getPixelValues() {
	//take a picture of the surface
	take_picture();
	std::vector<int> pixelValues;
	//fill the pixelValues vector object to the given size using the amount of columns
	for (int counter = 0; counter < constants::picture::COLUMNS; counter += 1) {
		//calculates the whiteness value of a pixel by taking a pixel halfway down the image at index counter
		int pixelValue = get_pixel((constants::picture::ROWS / 2), counter, 3);
		//add the calculated whiteness value to the end of the vector object
		pixelValues.push_back(pixelValue);
	}
	return pixelValues;
}

/**
 * @note Calculates wether a pixel is white or black and returns them in a vector object of type boolean
 * @param pixelValues Pass a vector object of pixelValues between 0 and 255.
 * @return An array of booleans where true correlates to a white pixel and false to a black pixel
 */
std::vector<bool> calculatePixelStates(std::vector<int> pixelValues) {
	printf("Defined pixel states\n");
	std::vector<bool> pixelStateValues;
	//for every pixel value, calculate if it is white or not
	for (int counter = 0; counter < pixelValues.size(); counter += 1) {
		//store the pixel whiteness value at this index in the pixelValues vector in the variable 'pixelValue'
		int pixelValue = pixelValues.at(counter);
		//if the pixel value is greater than the maximum specified value of black, it is therefore a white pixel
		if (pixelValue > constants::picture::MAXIMUM_BLACK_VALUE) {
			//add the value true to the end of the pixelValues object, signifying a white pixel
			pixelStateValues.push_back(true);
		}
			//otherwise, we know it is a black pixel
		else {
			//add the value false to the end of the pixelValues object, signifying a black pixel
			pixelStateValues.push_back(false);
		}
	}
	return pixelStateValues;
}

/**
 * @note Determines wether the robot is on a patch of red pixels
 * @param pixelRednessValues Pass a vector object of type int with values between 0 and 255 of the pixel redness values
 * @return Returns true if it is evaluated that the robot is on a red patch, otherwise false
 */
bool isRedPatch(std::vector<int> pixelRednessValues) {
	bool result = false;
	int totalRedPixels = 0;
	for (int counter = 0; counter < pixelRednessValues.size(); counter += 1) {
		if (pixelRednessValues.at(counter) >= constants::picture::MINIMUM_RED_VALUE) {
			totalRedPixels += 1;
		}
	}
	if (totalRedPixels >= constants::picture::patch::MINIMUM_RED_PIXELS) {
		result = true;
	}
	return result;
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
			totalWhitePixels += 1;
			const int pixelWeight = counter - (pixelStates.size() / 2);
			totalError += pixelWeight;
		}
	}
	totalError != 0 ? totalError /= totalWhitePixels : totalError = totalError;
	return totalError;
}

/**
 * @return Returns an signed integer value for the calculated error (currently for all pixels in the row). A negative
 * value shows that there are a higher weight of white pixels to the left, a positive value implies the same, except
 * to the right.
 */
int getError() {
	std::vector<int> pixelWhitenessValues = getPixelValues();
	std::vector<bool> pixelStateValues = calculatePixelStates(pixelWhitenessValues);
	//Pass getError the boolean pixelStates and return the calculated result
	return getError(pixelStateValues);
}


