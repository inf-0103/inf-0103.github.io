#include <stdio.h>

typedef union {
    int number;
    char word[4];
} my_u;

int main() {
    my_u a = {.word = "abc"};

    printf("%s\n", a.word);
}
