#include "main.h"

int main() {
	init();
	take_picture();
	printf("Pixels: %i\n%i\n%i\n%i\n%i\nEnd test\n", get_pixel(123, 123, 3), get_pixel(23, 23, 3), get_pixel(56, 56, 3), get_pixel(48, 48, 3), get_pixel(99, 99, 3));
	drive();
	return 0;
}
