#include <stdio.h>

/*
En variabel selv om den er konstant,
blir i C (i motsetning til C++) ikke regnet som et konstantuttrykk
som er tilgjengelig ved kompilering.
Derfor bruker vi preprosessoren i stedet for en variabel
av typen static const int
*/
#define LENGDE 5

void bubblesort(int *arr, int lengde);

int main() {
    int antall_tall = LENGDE;
    int talliste[LENGDE];
    for (int i = 0; i < antall_tall; i++) {
        printf("Oppgi tall %d: ", i + 1);
        scanf("%d", &talliste[i]);
    }

    bubblesort(talliste, antall_tall);

    printf("Tallene i sortert rekkefolge er: \n");


    for (int i = 0; i < antall_tall; i++) {
        printf("Tall %d er: %d\n", i + 1, talliste[i]);
    }

}

void bubblesort(int *arr, int lengde) {
    /*
    Sorterer en tabell med heltall i stigende rekkefølge
    ved å flytte på tallene i den samme tabellen
    */

    int *arr_slutt = arr +  lengde;
    // Peker på posisjonen i tabellen vi opererer på
    int *p = arr;
    while (p >= arr && p < (arr_slutt - 1)) {        
        if (*(p + 1) < *p) {
            /*
            Bytter om på to naboelementer dersom de ikke står i rekkefølge
            */
            int tmp = *p;
            *p = *(p + 1);
            *(p + 1) = tmp;
            if (p > arr) {
                p--;
            }
        } else {
            p++;
        }
    }
}
