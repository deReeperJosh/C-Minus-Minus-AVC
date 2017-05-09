#include "test_tapeSensor.h"
void test_getPixelValues(){
	std::cout << "Creating vector of type int";
	std::vector<int> test_pixelValues;
	std::cout << "Calling getPixelValues";
	getPixelValues(test_pixelValues, constants::picture::ROWS / 2);
	std::cout << "Printing values";
	for(int test_counter = 0; test_counter < test_pixelValues.size(); test_counter += 1){
		std::cout << "Value at: ";
		std::cout << test_counter;
		std::cout << "Equals: ";
		std::cout << test_pixelValues.at(test_counter);
	}
	std::cout << "Finished test";
}