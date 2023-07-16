#include "../include/window_linux.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static Window w;
static XEvent e;
static Display* d;

char* get_windowing_system() {
	char* session_type = getenv("XDG_SESSION_TYPE");
	if(strcmp(session_type, "") == 0)
		return "None";
	else
		return session_type;
}

Window* create_x11_window(unsigned int width, unsigned int height) {
	d = XOpenDisplay(NULL);
	if(d == NULL)
		puts("Can't Open X11 Display...");

	int screen = DefaultScreen(d);
	w = XCreateSimpleWindow(d, RootWindow(d, screen), 0, 0, width, height, 5, 1, 0);

	XSelectInput(d, w, ExposureMask | KeyPressMask);
	
	XMapRaised(d, w);
	return &w;
}

void do_window_loop() {
	XNextEvent(d, &e);
	if(e.type == Expose) {
	}
}
