#include <stdio.h>

typedef struct {
    union {
        int i_val;
        char c_val;
    };
    int doink;
} t_t;

int main() {
    t_t a = {.doink = 10, .i_val = 10};
    printf("%d %d\n", a.doink, a.c_val);
    printf("%d\n", sizeof(t_t));
}
