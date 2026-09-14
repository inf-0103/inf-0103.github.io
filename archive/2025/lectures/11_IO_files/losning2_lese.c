#include "losning2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("data", "r");
    header_t h;
    fread(&h, sizeof(header_t), 1, f);
    printf("Antall elementer å lese: %d\n", h.num_elements);
    if(h.magic_number != 0xaabbccdd) {
        printf("Feil filformat!\n");
    }
    element_t *elem = malloc(sizeof(element_t) * h.num_elements);
    fread(elem, sizeof(element_t), h.num_elements, f);
    for(int i = 0; i < h.num_elements; i++) {
        printf("Element %d: (%d, %d)\n", i, elem[i].x, elem[i].y);
    }
}
