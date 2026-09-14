#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t higher;
    uint8_t lower;
} verdi_t;

typedef union {
    uint32_t a;
    uint8_t b;
} verdi_u;

verdi_t min_funksjon_smart(uint32_t a, uint8_t b) {
    verdi_t ret;
    ret.higher = a;
    ret.lower = b;
    return ret;
}

typedef struct {
    char *data;
    uint32_t length;
    union {
        uint32_t capacity;
        char text[16];
    }
} string_t;

uint64_t min_funksjon(uint32_t a, uint8_t b) {
    return a << 32 + b;
}

int main() {
    printf("Storrelse: %lu\n", sizeof(verdi_t));
    printf("Storrelse union: %lu\n", sizeof(verdi_u));
    
    return 0;
}
