#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_NUMBER 0

#define window_x 30
#define window_y 30
#define window_width 100
#define window_height 100
#define border_width 0
#define border_color 0x000000
#define background_color 0x000000

int main() {
  Display *display = XOpenDisplay(NULL);
  if (display == NULL) {
    perror("XOpenDisplay:");
    return 0;
  }
  Window root_window = RootWindow(display, SCREEN_NUMBER);
  Window w = XCreateSimpleWindow(display, root_window, window_x, window_y,
                                 window_width, window_height, border_width,
                                 border_color, background_color);
  XMapWindow(display, w);
  XFlush(display);
  XUnmapWindow(display, w);
  XDestroyWindow(display, w);
  XCloseDisplay(display);
  return 0;
}
