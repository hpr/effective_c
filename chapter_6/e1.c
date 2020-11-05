// Repair the use-after-free defect from Listing 6-4.

//#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct { // working around opaque datatype DIR
  char* d_buf;
  char d_fd;
} DIR;

int closedir(DIR *dirp) {
  int result = close(dirp->d_fd);
  free(dirp->d_buf);
  free(dirp);
  return result;
}

int main(void) {
  DIR* dir = malloc(sizeof(DIR));
  dir->d_fd = 0;
  dir->d_buf = NULL;
  printf("%d\n", closedir(dir));
  return 0;
}
