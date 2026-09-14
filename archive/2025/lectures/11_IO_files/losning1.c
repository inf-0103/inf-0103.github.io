#include <stdio.h>

int main() {
    FILE *strm = fopen("hallo.txt", "r");
    for(int i = 0; i < 10; i++) {
        fprintf(strm, "AAA %d\n", i);
    }
    fclose(strm);
}
