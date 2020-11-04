// Modify the function from listing 5-11 to make it clear to the caller which file could not be opened.

#include <stdio.h>
#include <stdlib.h>

typedef struct {} object_t;

int do_something(void) {
  FILE *file1, *file2;
  object_t *obj;
  int ret_val = 0; // Initially return a successful return value

  file1 = fopen("a_file", "w");
  if (file1 == NULL) {
    ret_val = -1;
    puts("could not open file1");
    goto FAIL_FILE1;
  }

  file2 = fopen("another_file", "w");
  if (file2 == NULL) {
    ret_val = -1; // -2
    puts("could not open file2");
    goto FAIL_FILE2;
  }

  obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    ret_val = -1; // -3
    puts("could not allocate object");
    goto FAIL_OBJ;
  }

  // Operate on allocated resources

  /*
  switch (ret_val) {
  case 0: break;
  case -1: puts("could not open file1"); break;
  case -2: puts("could not open file2"); break;
  case -3: puts("could not allocate object"); break;
  default: puts("unknown error");
  }
  */
  
  // Clean up everything
  free(obj);
 FAIL_OBJ: // Otherwise, close only the resources we opened
  fclose(file2);
 FAIL_FILE2:
  fclose(file1);
 FAIL_FILE1:
  return ret_val;
}

int main(void) {
  do_something();
  return 0;
}
