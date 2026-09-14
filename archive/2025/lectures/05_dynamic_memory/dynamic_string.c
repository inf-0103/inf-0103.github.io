#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SHORT_STRING 16

typedef struct {
    char *data;
    uint32_t length;
    union {
        uint32_t capacity;
        char short_string[SHORT_STRING];
    };
} string_t;

string_t *create_string(const char *text) {
    size_t str_len = strlen(text);
    string_t *ret = calloc(sizeof(string_t), 1);
    ret->length = str_len + 1; // Including null byte
    if(str_len < SHORT_STRING) {
        memcpy(ret->short_string, text, str_len);
    } else {
        ret->data = calloc(str_len + 1, 1);
        memcpy(ret->data, text, str_len);
        ret->capacity = str_len + 1;
    }
    
    return ret;
}

void append_string(string_t *str, const char *text) {
    size_t new_string_len = strlen(text);
    size_t total_length = new_string_len + str->length;
    if(str->length < SHORT_STRING && total_length >= SHORT_STRING) {
        
    }
}

char *get_text(string_t *str) {
    if(str->length < SHORT_STRING) return str->short_string;
    return str->data;
}

int main() {
    string_t *str = create_string("Hello");
    string_t *str_long = create_string("Hello world, how are you doing? This is fine!");
    printf("%s\n", get_text(str));
    printf("%s\n", get_text(str_long));
}
