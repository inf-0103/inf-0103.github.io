#include <stdio.h>

int main() {
    /*
    Hvorfor formatet %llu? sizeof-operatoren returnerer en verdi av type `long long unsigned int`.
    Kompilatoren klager dersom vi bruker %d som er for type `int`.
    */
    printf("sizeof(int): %llu\n", sizeof(int));
    printf("sizeof(double): %llu\n", sizeof(double));
    printf("sizeof(char): %llu\n", sizeof(char));

    float f = 2.71828181828;
    printf("Storrelsen til flyttallet f: %llu\n", sizeof(f));

    int arr[10];
    int lengde = 403;
    int arr_vla[lengde];

    printf("Storrelsen til en statisk heltallstabell med 10 elementer: %llu\n", sizeof(arr));
    printf("Storrelsen til en variabel heltallstabell med %d elementer: %llu\n", lengde, sizeof(arr_vla));

    printf("sizeof(*int): %llu\n", sizeof(int*));
    printf("sizeof(*void): %llu\n", sizeof(void*));
    
    printf("sizeof(NULL): %llu\n", sizeof(NULL));
    return 0;
}
