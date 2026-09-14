#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char *data;
    uint32_t size;
    uint32_t capacity;
} string_t;

string_t *create_str(const char *data) {
    string_t *ret = calloc(sizeof(string_t), 1);
    uint32_t str_len = strlen(data);
    ret->data = calloc(str_len + 1, 1);
    memcpy(ret->data, data, str_len);
    ret->size = str_len;
    ret->capacity = str_len;
    return ret;
}

void append(string_t *str, const char *new_data) {
    uint32_t total_len = strlen(new_data) + str->size;
    printf("Appending %s\n", new_data);
    if(total_len > str->capacity) {
        printf("String to small (%d bytes), expanding to %d bytes!\n", str->capacity, total_len * 2);
        char *new_data = calloc(total_len * 2, 1);
        memcpy(new_data, str->data, str->size);
        str->capacity = total_len * 2;
        free(str->data);
        str->data = new_data;
    }
    memcpy(str->data + str->size, new_data, strlen(new_data));
    str->size = total_len;
}

int main() {
    string_t *str = create_str("Hel");
    append(str, "lo");
    printf("%s\n", str->data);
    for(int i = 0; i < 100; i++) {
        append(str, "lolo");
    }
    printf("%s\n", str->data);
}
