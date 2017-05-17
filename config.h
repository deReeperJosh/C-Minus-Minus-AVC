#ifndef C_MINUS_MINUS_AVC_CONFIG_H
#define C_MINUS_MINUS_AVC_CONFIG_H
namespace constants {
	namespace picture {
		namespace identifiers {
			static const int RED = 0;
			static const int GREEN = 1;
			static const int BLUE = 2;
			static const int WHITE = 3;
		}
		static const int MAXIMUM_POSSIBLE_PIXEL_VALUE = 255;
		static const int ROWS = 240;
		static const int COLUMNS = 320;
		static const int MAXIMUM_BLACK_VALUE = 127;
		static const int MINIMUM_BLACK_VALUE = 0;
		static const int MINIMUM_RED_VALUE = 100;
		static const int MINIMUM_GREEN_VALUE = 100;
		static const int MINIMUM_BLUE_VALUE = 100;
		namespace redPatch {
			static const int MINIMUM_RED_PIXELS = COLUMNS / 2;
			static const double MINIMUM_RATIO_VALUE = 2.5;
		}
	}
	namespace vehicle {
		namespace parts {
			static const int LEFT_MOTOR = 2;
			static const int RIGHT_MOTOR = 1;
		}
		static const int STABLE_SPEED = 100;
		static const int MAX_SPEED = 254;
		static const int SLEEP_TIME_SECONDS = 0;
		static const int SLEEP_TIME_MICROSECONDS = 5000;
	}
	namespace PID {
		static const double PROPORTIONAL_CONSTANT = 3;
		static const double DERIVATIVE_CONSTANT = 0.5;
		//we aren't using integral signal for the moment
		static const double INTEGRAL_CONSTANT = 0;
	}
	namespace server {
		//it would be nice to make this a constant
		static const int TOTAL_MESSAGE_CHARACTERS = 24;
		//it would be nice to make this a constant
		static char IP_ADDRESS[15] = {'1', '3', '0', '.', '1', '9', '5', '.', '6', '.', '1', '9', '6'};
		static const int PORT = 1024;
		//the message must be the length that send_to_server expects
		static char MESSAGE[TOTAL_MESSAGE_CHARACTERS] = {'P', 'l', 'e', 'a', 's', 'e', 0};
		static const int TOTAL_PASSKEY_CHARACTERS = 6;
	}
}
#endif //C_MINUS_MINUS_AVC_CONFIG_H
