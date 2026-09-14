#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t magic;
    uint32_t num_items;
} header_t;

typedef struct {
    uint8_t num1;
    char name[20];
} item_t;

int main() {
    FILE *f = fopen("output", "w");
    header_t h = {.magic = 0xff221122, .num_items = 2};
    item_t first = {.num1 = 16, .name = "Hello"};
    item_t second = {.num1 = 32, .name = "world"};
    fwrite(&h, sizeof(header_t), 1, f);
    fwrite(&first, sizeof(item_t), 1, f);
    fwrite(&second, sizeof(item_t), 1, f);
    fclose(f);
}
