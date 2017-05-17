#include "serverCommunication.h"

void openGate() {
	connect_to_server(constants::server::IP_ADDRESS, constants::server::PORT);
	send_to_server(constants::server::MESSAGE);
	//a character array to hold the server response message, the length is defined by TOTAL_MESSAGE_CHARACTERS
	char responseMessage[constants::server::TOTAL_MESSAGE_CHARACTERS];
	receive_from_server(responseMessage);
	//the passkey needs to be the length the send_to_server expects
	char passkey[constants::server::TOTAL_MESSAGE_CHARACTERS];
	//store the first 6 values of the response in the
	for (int counter = 0; counter < constants::server::TOTAL_PASSKEY_CHARACTERS; counter += 1) {
		passkey[counter] = responseMessage[counter];
	}
	//add the numeric value 0 to the end of the passkey to show it the passkey has ended terminated
	passkey[constants::server::TOTAL_PASSKEY_CHARACTERS + 1] = 0;
	send_to_server(passkey);
}