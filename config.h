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
		static const int STABLE_SPEED = 50;
		static const int SLEEP_TIME_SECONDS = 0;
		static const int SLEEP_TIME_MICROSECONDS = 5000;
	}
	namespace PID {
		static const int PROPORTIONAL_SCALE = 2;
	}

}

#endif //C_MINUS_MINUS_AVC_CONFIG_H
