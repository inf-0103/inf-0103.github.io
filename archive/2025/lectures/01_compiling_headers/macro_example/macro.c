#include <stdio.h>

#define SUM(x, y) x + y

int main(){
    int a, b, c;
    a = 3;
    b = 5;
    c = 2;
    int res = a * SUM(b, c);
    printf("%d", res);
    return 0;
}
