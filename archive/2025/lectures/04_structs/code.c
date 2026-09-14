#include <stdio.h>

typedef struct {
    int num;
    int val;
} nval;

nval test(int a, int b) {
    return (nval){.num = a, .val = b};
}

void print_s(nval to_print) {
    printf("Num: %d, value: %d\n", to_print.num, to_print.val);
}

int main() {
    nval t = test(10, 22);
    nval t2 = {.num = 1, .val = 2};
    nval t3 = {0};
    nval t4;
    print_s(t);
    print_s(t2);
    print_s(t3);
    print_s(t4);
    printf("Size: %llu\n", sizeof(nval));
}
