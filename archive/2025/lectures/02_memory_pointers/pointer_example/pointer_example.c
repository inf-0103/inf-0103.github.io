#include "stdio.h"

void foo(int x) {
    x = x + x;
    printf("x i foo(): %d\n", x);
    printf("x i foo() har addressen: %p\n", &x);
}

void bar(int *x_peker) {
    int x = *x_peker;
    *x_peker = x + x;
    printf("x_peker i bar() er: %p\n", x_peker);
    printf("x_peker i bar() peker til verdien: %d\n", *x_peker);
}

int main() {
    int x = 5;
    printf("x i main() ved start: %d\n", x);
    foo(x);
    printf("x i main() etter foo(): %d\n", x);
    int *x_peker = &x;
    printf("x_peker i main() er: %p\n", x_peker);
    bar(x_peker);
    printf("x i main() etter bar(): %d\n", x);
    return 0;
}
