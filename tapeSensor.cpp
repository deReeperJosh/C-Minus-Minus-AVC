#include "E101.h"
#include "iostream"
#include "vector"

using namespace std;
const int PICTURE_ROWS = 240;
const int PICTURE_COLUMNS = 320;

void getPixelValues(std::vector<int> &pixelValues, const int size) {
	take_picture();
	for (int counter = 0; counter < size; counter += 1) {
		int pixelValue = get_pixel((PICTURE_ROWS / 2), counter, 3);
		pixelValues.push_back(pixelValue);
	}
}

void calculatePixelStates(std::vector<bool> &pixelStates, const int size, std::vector<int> pixelValues) {
	const int MAXIMUM_BLACK_VALUE = 127;
	for (int counter = 0; counter < pixelValues.size() - 1; counter += 1) {
		int pixelValue = pixelValues.at(counter);
		if (pixelValue > MAXIMUM_BLACK_VALUE) {
			pixelValues.push_back(true);
		}
		else {
			pixelValues.push_back(false);
		}
	}
}

int getError(std::vector<bool> pixelStates) {
	int totalError = 0;
	int totalWhitePixels = 0;
	for (int counter = 0; counter < pixelStates.size() - 1; counter += 1) {
		if (pixelStates.at(counter) == true) {
			totalWhitePixels += 1;
			const int pixelWeight = counter - (pixelStates.sixe() / 2);
			totalError += pixelWeight;
		}
	}
	return totalError;
}

int getError(){
	std::vector<int> pixelWhitenessValues;
	getPixelValues(pixelWhitenessValues, PICTURE_ROWS);
	std::vector<bool> pixelStateValues;
	calculatePixelStates(pixelStateValues, PICTURE_ROWS, pixelWhitenessValues);
	return getError(pixelStateValues);
}

int main() {
	getError();
	return 0;
}
