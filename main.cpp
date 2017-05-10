#include "main.h"

int main() {
	std::cout << "Initialising\n";
	init();
	std::cout << "Calling drive\n";
	drive();
	std::cout << "Finished drive\nPress a key to dun finysh :p.\n";
	std::cin.get();
	return 0;
}
