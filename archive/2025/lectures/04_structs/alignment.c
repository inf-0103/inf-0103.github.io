#include <stdio.h>

typedef struct {
    char a;
    int b;
    char c;
} struct_a;

typedef struct {
    int b;
    char a;
    char c;
} struct_b;

int main() {
    printf("%lu\n", sizeof(struct_a));
    printf("%lu\n", sizeof(struct_b));
}
