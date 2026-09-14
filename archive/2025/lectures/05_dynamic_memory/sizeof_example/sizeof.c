#include <stdio.h>

int main() {
    /*
    Hvorfor formatet %zd? sizeof-operatoren returnerer en verdi av type `long long unsigned int`, men
    for enkelthets skyld kan vi skrive dette som %zd som alltid vil være kompatibelt med sizeof()
    Kompilatoren klager dersom vi bruker %d som er for type `int`.
    */
    printf("sizeof(int): %zd\n", sizeof(int));
    printf("sizeof(double): %zd\n", sizeof(double));
    printf("sizeof(char): %zd\n", sizeof(char));

    float f = 2.71828181828;
    printf("Storrelsen til flyttallet f: %zd\n", sizeof(f));

    int arr[10];
    int lengde = 403;
    int arr_vla[lengde];

    printf("Storrelsen til en statisk heltallstabell med 10 elementer: %zd\n", sizeof(arr));
    printf("Storrelsen til en variabel heltallstabell med %d elementer: %zd\n", lengde, sizeof(arr_vla));

    printf("sizeof(int*): %zd\n", sizeof(int*));
    printf("sizeof(void*): %zd\n", sizeof(void*));
    
    printf("sizeof(NULL): %zd\n", sizeof(NULL));
    return 0;
}
