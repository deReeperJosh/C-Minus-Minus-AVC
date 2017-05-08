#include "E101.h"
#include "iostream"
#include "vector"
using namespace std;

const int PICTURE_ROWS = 240;
const int PICTURE_COLUMNS = 320;

void getPixelValues(std::vector<int>& pixelValues, const int size) {
	take_picture();
	for (int counter = 0; counter < size; counter += 1) {
		int pixelValue = get_pixel((PICTURE_ROWS / 2), counter, 3);
		pixelValues.push_back(pixelValue);
	}
}

void calculatePixelStates(std::vector<bool>& pixelStates, const int size, std::vector<int> pixelValues){
	const int MAXIMUM_BLACK_VALUE = 127;
	for(int counter = 0; counter < pixelValues.size() - 1; counter += 1){
		int pixelValue = pixelValues.at(counter);
		if(pixelValue > MAXIMUM_BLACK_VALUE){
			pixelValues.push_back(true);
		}
		else{
			pixelValues.push_back(false);
		}
	}
}

int main() {
	std::vector<int> pixelWhitenessValues;
	getPixelValues(pixelWhitenessValues, PICTURE_COLUMNS);
	std::vector<bool> pixelStateValues;
	calculatePixelStates(pixelStateValues, PICTURE_ROWS, pixelWhitenessValues);
	return 0;
}
