#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("tekst.txt", "r");
    char data[1000];
    memset(data, 0, 1000);
    fread(data, 1, 1000, f);
    printf("%s\n", data);
    char *ord = strtok(data, " ");
    while(ord) {
        printf("Ordet er %s\n", ord);
        ord = strtok(NULL, " ");
    }

    printf("%s\n", data);
    
}
