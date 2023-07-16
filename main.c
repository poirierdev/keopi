#ifdef __linux__
	#include "include/window_linux.h"
#endif

int main (void) {
	create_x11_window(500,500);
	return 0;
}
