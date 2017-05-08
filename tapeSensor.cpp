#include "tapeSensor.h"

using namespace std;

/**
 * @param pixelValues Pass an vector object, the function works on this parameter by reference.
 * @param size Pass the absolute size that the vector should be.
 * */
void getPixelValues(std::vector<int> &pixelValues, const int size) {
	take_picture();
	for (int counter = 0; counter < size; counter += 1) {
		int pixelValue = get_pixel((constants::picture::ROWS / 2), counter, 3);
		pixelValues.push_back(pixelValue);
	}
}

/**
 * @param pixelStates Pass a vector object of type boolean; it will be worked on by reference. The function fills with
 * true if the value in pixelValues with the corresponding index evaluates to white, otherwise the function fills with
 * false.
 * @param size Pass the absolute size that the pixelStates vector should be.
 * @param pixelValues Pass a vector object of pixelValues between 0 and 255.
 */
void calculatePixelStates(std::vector<bool> &pixelStates, const int size, std::vector<int> pixelValues) {
	for (int counter = 0; counter < pixelValues.size() - 1; counter += 1) {
		int pixelValue = pixelValues.at(counter);
		if (pixelValue > constants::picture::MAXIMUM_BLACK_VALUE) {
			pixelValues.push_back(true);
		}
		else {
			pixelValues.push_back(false);
		}
	}
}

/**
 * @param pixelStates Pass a vector object representing if a pixel evaluated to white (true) or black (false).
 * @return Returns an signed integer value for the calculated error. A negative value shows that there are a higher
 * weight of white pixels to the left, a positive value implies the same, except to the right.
 */
int getError(std::vector<bool> pixelStates) {
	int totalError = 0;
	int totalWhitePixels = 0;
	for (int counter = 0; counter < pixelStates.size() - 1; counter += 1) {
		if (pixelStates.at(counter) == true) {
			totalWhitePixels ++1;
			const int pixelWeight = counter - (pixelStates.sixe() / 2);
			totalError += pixelWeight;
			totalError/numWhitePixels;
		}
	}
	return totalError;
}

/**
 * @return Returns an signed integer value for the calculated error (currently for all pixels in the row). A negative
 * value shows that there are a higher weight of white pixels to the left, a positive value implies the same, except
 * to the right.
 */
int getError() {
	std::vector<int> pixelWhitenessValues;
	getPixelValues(pixelWhitenessValues, constants::picture::COLUMNS);
	std::vector<bool> pixelStateValues;
	calculatePixelStates(pixelStateValues, constants::picture::ROWS, pixelWhitenessValues);
	return getError(pixelStateValues);
}
