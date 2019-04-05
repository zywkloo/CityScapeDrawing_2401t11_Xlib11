#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <time.h>

#define PANEL 20
#define HEIGHT 260
#define GAP   5
#define DOOR_H 30
#define DOOR_W 18



Display *display;
Window   win;
GC       gc;

// Draw the dual doors with bottom centered at x.
// Draw two door handles as well
void drawDoors(int x) {
  // complete the function
  XSetForeground(display, gc,  0xFFFFFF);
  XFillRectangle(display, win, gc, x-DOOR_W , HEIGHT-DOOR_H ,DOOR_W, DOOR_H );
  XSetForeground(display, gc,  0x000000);
  XDrawRectangle(display, win, gc, x-DOOR_W , HEIGHT-DOOR_H ,DOOR_W, DOOR_H);
  XSetForeground(display, gc,  0xFFFFFF);
  XFillRectangle(display, win, gc, x, HEIGHT-DOOR_H ,DOOR_W, DOOR_H );
  XSetForeground(display, gc,  0x000000);
  XDrawRectangle(display, win, gc, x, HEIGHT-DOOR_H ,DOOR_W, DOOR_H);
  XDrawLine(display, win, gc, x-GAP, HEIGHT-DOOR_H/2-GAP/2, x-GAP, HEIGHT-DOOR_H/2+GAP);
  XDrawLine(display, win, gc, x+GAP, HEIGHT-DOOR_H/2-GAP/2, x+GAP, HEIGHT-DOOR_H/2+GAP);
}

// Draw a building with the left side at the given x offset and with a
// floor width of w and with h floors
void drawBuilding(int x, int w, int h) {
  int color1 = (int)(rand()/(double)RAND_MAX*128);
  int color2 = (int)(rand()/(double)RAND_MAX*128);
  int color3 = (int)(rand()/(double)RAND_MAX*128);
  int randC = 256*256*color1+256*color2+color3;
  // complete the function
  XSetForeground(display, gc, randC);
  int b_h = DOOR_H + (h -1)*PANEL + h*GAP;
  int b_w = w*PANEL+ (w+1)*GAP;
  XFillRectangle(display, win, gc, x , 260-(b_h) ,b_w, b_h );
  XFlush(display);
  XSetForeground(display, gc,  0xFFFFFF);
  XDrawRectangle(display, win, gc, x , 260-(b_h) ,b_w, b_h );
  XFlush(display);

  for (int j=0 ; j<w ;j++){
    for (int i=0 ; i<h-1 ; i++){
      XSetForeground(display, gc,  0xFFFFFF);
      XFillRectangle(display, win, gc, x+GAP+j*(GAP+PANEL) , 260-(b_h)+GAP+i*(GAP+PANEL) ,PANEL, PANEL );
      XSetForeground(display, gc,  0x000000);
      XDrawRectangle(display, win, gc, x+GAP+j*(GAP+PANEL) , 260-(b_h)+GAP+i*(GAP+PANEL) ,PANEL, PANEL );
    }
  }
  drawDoors(x+b_w/2);
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

