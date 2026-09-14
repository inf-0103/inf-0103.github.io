#include <stdio.h>


void bubblesort(int *arr, int lengde);

int main() {
    int antall_tall;
    printf("Antall tall som skal sorteres: ");
    scanf("%d", &antall_tall);
    int talliste[antall_tall];
    /*
    Resten av programmet er identisk med det forrige eksemplet
    vårt
    */
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
