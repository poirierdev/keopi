#include <X11/Xlib.h>

char* get_windowing_system();
Window* create_x11_window(unsigned int, unsigned int);
void do_window_loop();

