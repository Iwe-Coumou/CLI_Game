#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_validate_mode(char *input) {
  if (strcmp(input, "host") == 0 || strcmp(input, "join") == 0) return input;
  return NULL;
}

int main(int argc,char *argv[]) {
  char *mode = _validate_mode(argv[1]);
  if (!mode) {
    fprintf(stderr, "usage: game host\n"
                    "       game join <ip>\n");
    exit(1);
  } else {
    printf("Running in %s mode...\n", mode);
  }
}
