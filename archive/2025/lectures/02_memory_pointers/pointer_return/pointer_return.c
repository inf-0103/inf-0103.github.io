#include <stdio.h>

int *foo() {
    int verdi = 204;
    int *verdi_peker = &verdi;
    return verdi_peker;
}

int main() {
    int *p = foo();
    int verdi = *p;
    printf("p peker til verdien: %d\n", verdi);
    return 0;
}
