#include <stdio.h>

int sum_of_digits(int num) {
    int result = 0;
    int number = num;
    while(number != 0) {
        result += number % 10;
        number /= 10;
    }
    return result;
}

void person(int dag, int maaned, int aar, int individnr, int kontroll) {
    int siff1 = sum_of_digits(dag) + sum_of_digits(maaned) + sum_of_digits(aar) + sum_of_digits(individnr);
    siff1 %= 11;
    if(siff1 != 0) siff1 = 11 - siff1;
    int siff2 = sum_of_digits(dag) + sum_of_digits(maaned) + sum_of_digits(aar) + sum_of_digits(individnr) + siff1;
    siff2 %= 11;
    if(siff2 != 0) siff2 = 11 - siff2;

    int kontroll2 = siff1 * 10 + siff2;
    if(kontroll2 == kontroll) printf("IS CORRECT\n");
    printf("%d %d\n", kontroll2, kontroll);

    
}

int main() {
    person(7, 1, 88, 469, 39);
}
