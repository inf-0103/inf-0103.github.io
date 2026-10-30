#include <stdio.h>
#include <string.h>

/*
  Note that this can be done in many ways. My approach is probably quite
  primitive.
*/

// reads the next (at most) 5 characters in the file without moving the file
// pointer, returns number of chars read
size_t look_ahead(FILE* fp, char *buf) {
  size_t nc = fread(buf, sizeof(char), 5, fp);
  buf[nc] = '\0';

  // rewind nc characters as fread moves the file pointer
  fseek(fp, -nc, SEEK_CUR);

  return nc;
}

int main() {
  FILE *input = fopen("moby_dick.txt", "r");
  FILE *output = fopen("moby_dick_fixed.txt", "w");

  char whale_buf[6];

  // the idea is this: for each character in the file, read 5 characters ahead
  // and see if we get "whale". if so do the replacement, otherwise just write
  // a single character from one file to the other. if look_ahead returns fewer
  // than 5 characters then 1) it can't be whale and 2) it's the last
  // characters of the file
  while (look_ahead(input, whale_buf) > 4) {
    if (!strcmp(whale_buf, "whale")) {
      fprintf(output, "cetacean (but neither dolphin nor porpoise)");
      fseek(input, 5, SEEK_CUR);  // skips "whale" in the input
    } else {
      fprintf(output, "%c", fgetc(input));
    }
  }

  // at this point there are some characters in whale_buf that must be written to
  // file
  fprintf(output, "%s", whale_buf);
}
