#include <stdio.h>

int main(){
    int a = 4;
    int b = 9;
    int *tall_sum_peker = &(a + b);
    printf("Summen av de to tallene er: %d", *tall_sum_peker);
}
