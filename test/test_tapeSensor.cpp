#include "test_tapeSensor.h"
void test_getPixelValues(){
	printf("Started test_getPixelValues\n");
	printf("Creating vector of type int\n");
	std::vector<int> test_pixelValues;
	printf("Calling getPixelValues\n");
	getPixelValues(test_pixelValues, constants::picture::ROWS);
	printf("Printing values\n");
	for(int test_counter = 0; test_counter < test_pixelValues.size(); test_counter += 1){
		printf("Value at: %i equals %i\n", test_counter, test_pixelValues.at(test_counter));
	}
	printf("Finished test_getPixelValues\n");
}

void test_calculatePixelStates(){
	printf("Started\n");
	printf("Creating vector of type int\n");
	std::vector<int> test_pixelValues;
	printf("Calling getPixelValues\n");
	getPixelValues(test_pixelValues, constants::picture::COLUMNS);
	printf("Creating vector of type bool\n");
	std::vector<bool> test_pixelStateValues;
	printf("Calling getPixelStates\n");
	calculatePixelStates(test_pixelStateValues, constants::picture::COLUMNS, test_pixelValues);
	printf("Printing pixel states\n");
	for(int test_counter = 0; test_counter < test_pixelValues.size(); test_counter += 1){
		printf("States at: %i %s white\n", test_counter, test_pixelValues.at(test_counter) ? "is" : "isn't");
	}
}