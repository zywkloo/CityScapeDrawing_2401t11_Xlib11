#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <time.h>

#define PANEL 20
#define HEIGHT 260
#define GAP   5


Display *display;
Window   win;
GC       gc;

// Draw the dual doors with bottom centered at x.
// Draw two door handles as well
void drawDoors(int x) {
  // complete the function
}

// Draw a building with the left side at the given x offset and with a
// floor width of w and with h floors
void drawBuilding(int x, int w, int h) {
  // complete the function
}



int main() {
   // Opens connection to X server
   display = XOpenDisplay(NULL);

   // Create a simple window
   win = XCreateSimpleWindow(display,  // our connection to server
           RootWindow(display, 0), // parent window (none in this example)
           0, 0,                  // x,y (w.r.t. parent ... ignored here)
           130, 260,                  // width, height
           0,               // border width
           0x000000,            // border color (ignored in this example)
               0xFFFFFF);              // background color

   // Set the title of the window
   XStoreName(display, win, "My First X Window");

   // Make it visible
   XMapWindow(display, win);
   XFlush(display);
   usleep(20000);  // sleep for 20 milliseconds.


   // Get the GC
   gc = XCreateGC(display, win, 0, NULL);

   // Wait until user presses a key on keyboard
   srand(time(NULL));
   drawBuilding(10, (int)(rand()/(double)RAND_MAX*3) + 2,
            (int)(rand()/(double)RAND_MAX*9) + 2);
   XFlush(display);
   getchar();

   // Clean up and close the window
   XUnmapWindow(display, win);
   XDestroyWindow(display, win);
   XCloseDisplay(display);
}

