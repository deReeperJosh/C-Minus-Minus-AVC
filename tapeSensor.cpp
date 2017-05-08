#include "E101.h"
using namespace std;

const int PICTURE_ROWS = 240;
const int PICTURE_COLUMNS = 320;

int *getPixelValues() {
	take_picture();
	int pixelValues[PICTURE_COLUMNS];
	for (int counter = 0; counter < PICTURE_COLUMNS; counter += 1) {
		pixelValues[counter] = get_pixel(counter, (PICTURE_ROWS / 2), 3);
		cout << get_pixel(counter, (PICTURE_ROWS / 2), 3);
	}
	return pixelValues;
}

int getError() {
	return getPixelValues()[0];
}

int main() {
	const int error = getError();
	return 0;
}