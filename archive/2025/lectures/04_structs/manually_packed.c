#include <stdio.h>

typedef struct {
    int value;
    char val2;
} strange;

typedef struct {
    char val1;
    int val2;
    char val3;
} verystrange;

void print_strange(strange to_print) {
    printf("Value: %d, val2: %d\n", to_print.value, to_print.val2);
}

int main() {
    strange a = {.value = 10, .val2 = 2};
    strange fake = {0};
    strange *b = (strange *)((char *)(&a) + 5);
    b->value = 100;
    b->val2 = 10;
    print_strange(a);
    print_strange(*b);
    printf("Strange size: %llu\n", sizeof(strange));
    printf("Verystrange size: %llu\n", sizeof(verystrange));
}
