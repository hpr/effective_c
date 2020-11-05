// Perform additional testing of the program from Listing 6-11 by using dmalloc. Try varying inputs to the program to identify other memory management defects.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DMALLOC
#include "dmalloc.h"
#endif

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
  free(msg);
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    /* the error message won't be more than 80 chars */
    char *errmsg = (char *)malloc(80);
    sprintf(
      errmsg, 
      "Sorry %s,\nUsage: caesar secret_file keys_file [output_file]\n",
      getenv("USER")
    );
    usage(errmsg);
    free(errmsg);
    exit(EXIT_FAILURE);
  }
  //---snip---
  exit(EXIT_SUCCESS);
}
