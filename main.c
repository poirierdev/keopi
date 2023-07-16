#ifdef __linux__
	#include "include/window_linux.h"
#endif
#include <stdio.h>

int main (void) {
	Window* w;
	w = create_x11_window(500,500);
	puts("Ctrl+c to kill this for now.");
	while(1) {
		do_window_loop();
	}
	return 0;
}
