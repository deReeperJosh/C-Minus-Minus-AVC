#include "main.h"

int main() {
	std::cout << "Initialising\n";
	init();
	//Opening the gate, modify if needed
	connect_to_server(); //put in IP address and port
	recieve_from_server(); //here we actually get a password from the server
	send_to_server(); //put in password
	
	std::cout << "Calling drive\n";
	drive();
	std::cout << "Finished drive\nPress a key to dun finysh :p.\n";
	std::cin.get();
	return 0;
}
