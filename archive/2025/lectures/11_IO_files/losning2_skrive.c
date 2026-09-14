#include "losning2.h"
#include <stdio.h>

int main() {
    FILE *f = fopen("data", "w");
    header_t hdr = {.magic_number = 0xaabbccdd, .num_elements = 2};
    element_t e1 = {.x = 1, .y = 2};
    element_t e2 = {.x = 3, .y = 4};

    fwrite(&hdr, sizeof(header_t), 1, f);
    fwrite(&e1, sizeof(element_t), 1, f);
    fwrite(&e2, sizeof(element_t), 1, f);
    fclose(f);
    
}
