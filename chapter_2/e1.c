// Add a retrieve function to the counting example from Listing 2-6 to retrieve the current value of counter.

#include <stdio.h>

static unsigned int counter = 0;

void increment(void) {
  counter++;
  printf("%d ", counter);
}

void retrieve(void) {
  printf("\nretrieve: %d\n", counter);
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
    retrieve();
  }
  return 0;
}
