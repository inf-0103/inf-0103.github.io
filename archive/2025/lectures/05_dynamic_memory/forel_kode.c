// strings
// malloc
// free
// strlen
// memcpy
//
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char *data;
    uint32_t size;
    uint32_t capacity;
} string_t;

string_t *create_string(const char *str) {
    string_t *ret = calloc(sizeof(string_t), 1);
    ret->size = strlen(str);
    ret->capacity = strlen(str);
    ret->data = calloc(strlen(str) + 1, 1);
    memcpy(ret->data, str, strlen(str));
    return ret;
}

void append_string(string_t *str, const char *data) {
    uint32_t total_length = str->size + strlen(data);
    if(total_length > str->capacity) {
        char *new_data = calloc(total_length * 2, 1);
        memcpy(str->data, new_data, str->size);
        memcpy(data, new_data + str->size, strlen(data));
        free(str->data);
        str->data = new_data;
    }
}

int main() {
    string_t *str = create_string("Hallo");
    char *hallo = str->data;
    append_string(str, " Verden!");
    printf("%s\n", hallo);
}

