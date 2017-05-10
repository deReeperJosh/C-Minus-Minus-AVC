#ifndef C_MINUS_MINUS_AVC_CONFIG_H
#define C_MINUS_MINUS_AVC_CONFIG_H

namespace constants {
	namespace picture {
		static const int MAXIMUM_POSSIBLE_PIXEL_VALUE = 255;
		static const int ROWS = 240;
		static const int COLUMNS = 320;
		static const int MAXIMUM_BLACK_VALUE = 127;
		static const int MINIMUM_BLACK_VALUE = 0;
		static const int MINIMUM_RED_VALUE = 100;
		static const int MINIMUM_GREEN_VALUE = 100;
		static const int MINIMUM_BLUE_VALUE = 100;
		namespace redPatch{
			static const int MINIMUM_RED_PIXELS = COLUMNS / 2;
			static const double MINIMUM_RATIO_VALUE = 2.5;
		}
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

}

#endif //C_MINUS_MINUS_AVC_CONFIG_H