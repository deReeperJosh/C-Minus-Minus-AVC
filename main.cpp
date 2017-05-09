#include "main.h"

int main() {
	std::cout << "Initialising";
	init();
	std::cout << "Calling drive";
	drive();
	std::cout << "Finished drive";
	std::cin.get();
	return 0;
}
