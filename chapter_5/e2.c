// Change the find_element function from Listing 5-13 to return the position of the key in a. Don't forget to return an error indication if the keu is not found.

#include <stdlib.h>
#include <stdio.h>

size_t find_element(size_t len, int arr[len], int key) {
  size_t pos = (size_t)-1;
  // traverse arr and search for key
  for (size_t i = 0; i < len; ++i) {
    if (arr[i] == key) {
      pos = i;
      break; // terminate loop
    }
  }
  if (pos == (size_t)-1) puts("not found");
  return pos;
}

int main(void) {
  int arr1[] = { 1, 2, 3 };
  printf("%zd\n", find_element(sizeof(arr1), arr1, 3));
  printf("%zd\n", find_element(sizeof(arr1), arr1, 4));
  return 0;
}
