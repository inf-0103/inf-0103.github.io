#include <stdint.h>

typedef struct {
    uint32_t magic_number;
    uint32_t num_elements;
} header_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} element_t;
