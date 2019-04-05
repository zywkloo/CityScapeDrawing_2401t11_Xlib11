#include <stdio.h>

// function getPermit() returns the next available permit or
// 0 if none are available. 
int getPermit() {
	static int i = 0;
	i += 11;
  // complete the function 
	return i>55? 0 :i;
  
}


int main() {

 int permit = 0;

 while (permit = getPermit())
   printf("Got permit P%d\n", permit);

 printf("No more permits left\n");

}
