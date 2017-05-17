#ifndef C_MINUS_MINUS_AVC_CONFIG_H
#define C_MINUS_MINUS_AVC_CONFIG_H
namespace constants {
	namespace picture {
		static const int ROWS = 240;
		static const int COLUMNS = 320;
		static const int MAXIMUM_BLACK_VALUE = 127;
	}
	namespace vehicle {
		namespace parts {
			static const int LEFT_MOTOR = 1;
			static const int RIGHT_MOTOR = 2;
		}
		static const int STABLE_SPEED = 100;
		static const int SLEEP_TIME_SECONDS = 0;
		static const int SLEEP_TIME_MICROSECONDS = 5000;
	}
	namespace PID {
		static const int PROPORTIONAL_SCALE = 2;
	}
	namespace server {
		static const int TOTAL_MESSAGE_CHARACTERS = 24;
		static char IP_ADDRESS[15] = {'1', '3', '0', '.', '1', '9', '5', '.', '6', '.', '1', '9', '6'};
		static const int PORT = 1024;
		//the message must be the length that send_to_server expects
		static char MESSAGE[TOTAL_MESSAGE_CHARACTERS] = {'P', 'l', 'e', 'a', 's', 'e', 0};
		static const int TOTAL_PASSKEY_CHARACTERS = 6;
	}
}
#endif //C_MINUS_MINUS_AVC_CONFIG_H
