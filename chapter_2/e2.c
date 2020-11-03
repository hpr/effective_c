// Declare an array of three pointers to functions and invoke the appropriate function based on an index value passed in as an argument.

#include <stdio.h>

void (*funcs[3])(void);

void c2e2(int i) {
  funcs[i]();
}

void sayHello(void) {
  puts("Hello");
}

void sayGoodbye(void) {
  puts("Goodbye");
}

int main(void) {
  funcs[0] = sayGoodbye;
  funcs[1] = sayHello;
  funcs[2] = sayGoodbye;
  c2e2(1);
  return 0;
}
