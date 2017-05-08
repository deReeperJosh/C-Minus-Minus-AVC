#include "E101.h"
using namespace std;

const int PICTURE_ROWS = 240;
const int PICTURE_COLUMNS = 320;

int getError() {
	return get_pixel()[0];
}

int *getPixelValues() {
	take_picture();
	int pixelValues[PICTURE_COLUMNS];
	for (int counter = 0; counter < PICTURE_COLUMNS; counter += 1) {
		pixelValues[counter] = get_pixel(counter, PICTURE_ROWS / 2, 3);
		cout << get_pixel(counter, PICTURE_ROWS / 2, 3);
	}
	return pixelValues;
}

int main() {
	const int error = getError();
	return 0;
}