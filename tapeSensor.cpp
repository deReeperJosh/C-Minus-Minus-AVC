#include "E101.h"

int getError() {
	const int picture = take_picture();
}

int main() {
	const int error = getError();
	return 0;
}