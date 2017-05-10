#include "tapeSensor.h"

using namespace std;

/**
 * @note Finds the whiteness values of each of the pixels in the centre row from a previously taken picture
 * @param whichColor Insert 0 for Red, 1 for Green, 2 for Blue, 3 for White
 * @return A vector object of type int containing the pixel whiteness values (between 0 and 255) of the middle row
 * */
std::vector<int> getPixelValues(int whichColor) {
	std::vector<int> pixelValues;
	//fill the pixelValues vector object to the given size using the amount of columns
	for (int counter = 0; counter < constants::picture::COLUMNS; counter += 1) {
		//calculates the whiteness value of a pixel by taking a pixel halfway down the image at index counter
		int pixelValue = get_pixel((constants::picture::ROWS / 2), counter, whichColor);
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
 * @note Calculates the total pixels within a range
 * @param minimumValue Pass an integer value for the minimum possible value a pixel can be to evaluate to true
 * @param maximumValue Pass an integer value for the maximum possible value a pixel can be to evaluate to false
 * @param pixelValues Pass a vector object of type int containing the values of the pixels to be evaluated
 * @return Returns the total amount of pixels in the pixelValues vector which are greater than the or equal to minimum
 * value and less than or equal to the maximum value
 */
int totalPixelsWithinRange(const int minimumValue, const int maximumValue, std::vector<int> pixelValues) {
	int totalPixelsWithinRange = 0;
	for (int counter = 0; counter < pixelValues.size(); counter += 1) {
		currentValue = pixelValues.at(counter);
		if (currentValue <= minimumValue && currentValue >= maximumValue) {
			totalPixelsWithinRange += 1;
		}
	}
	return totalPixelsWithinRange;
}

/**
 * @note Averages the values of the pixels in a vector of integers
 * @param pixelValues Pass a vector object of type int
 * @return Returns the average of all the values in the argument pixelValues
 */
int averagePixelValues(std::vector<int> pixelValues) {
	int totalValues = 0;
	for (int counter = 0; counter < pixelValues.size(); counter += 1) {
		totalValues += pixelValues.at(counter);
	}
	return totalValues / pixelValues.size();
}

/**
 * @note Determines wether the robot is on a redPatch of red pixels
 * @param pixelRednessValues Pass a vector object of type int with values between 0 and 255 of the pixel redness values
 * @return Returns true if it is evaluated that the robot is on a red redPatch, otherwise false
 */
bool isRedPatch(std::vector<int> pixelRednessValues) {
	bool result = false;
	//Pass a value 1 to signify that the getPixelValues method should find the red values for the pixels
	std::vector<int> pixelRednessValues = getPixelValues(0);
	int totalRedPixels = totalPixelsWithinRange(constants::picture::redPatch::MINIMUM_RED_PIXELS,
												constants::picture::MAXIMUM_POSSIBLE_PIXEL_VALUE, pixelRednessValues);
	//If the total amount of red pixels meets the requirements, the ratio of red values to green values can then be
	//	calculated. A number of red pixels is used as it is a good way to think about the problem knowing that there's
	//	black either side
	if (totalRedPixels >= constants::picture::redPatch::MINIMUM_RED_PIXELS) {
		//It is unnecessary to find the greeness and blueness levels outside of this scope
		std::vector<int> pixelGreenessValues = getPixelValues(1);
		std::vector<int> pixelBluenessValues = getPixelValues(2);
		int averageNonRedValues =
			(averagePixelValues(pixelGreenessValues) + averagePixelValues(pixelBluenessValues)) / 2;
		int averageRedValues = averageRedValues(pixelRednessValues);
		double ratioOfAverageRedValuesToNonRedValues = (double) averageNonRedValues / (double) averageNonRedValues;
		if(ratioOfAverageRedValuesToNonRedValues >= constants::picture::redPatch::MINIMUM_RATIO_VALUE){
			result = true;
		}
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
	//firstly we need to take a picture. It shouldn't be taken at any other point in the program
	take_picture();
	//A value of 3 signifies that the getPixelValues method should find the whiteness values
	std::vector<int> pixelWhitenessValues = getPixelValues(3);
	std::vector<bool> pixelStateValues = calculatePixelStates(pixelWhitenessValues);
	//Pass getError the boolean pixelStates and return the calculated result
	return getError(pixelStateValues);
}


