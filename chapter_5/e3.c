// Fix the remaining bug in the absolute_value function in Listing 5-14.

#include <stdio.h>
#include <limits.h>

int absolute_value(int a) {
  if (a == INT_MIN) {
    puts("can't take abs of INT_MIN");
    return a;
  }
  if (a < 0) {
    return -a;
  }
  return a;
}

int main(void) {
  printf("%d\n", absolute_value(-5));
  printf("%d\n", absolute_value(INT_MIN));
}
