#include <stdio.h>
#include "shapes.h"
#include "rectangle.h"
#include "circle.h"

int main() {
    char valg;
    printf("Velg geometrisk figur, c for sirkel, r for rektangel: ");
    scanf("%c", &valg);
    printf("\n");
    printf("Ditt valg er: %c\n", valg);
    if (valg == 'r'){
        rektangel_dialog();
    } else {
        sirkel_dialog();
    }
    printf("Ha en fin dag!\n");
    return 0;
}

void rektangel_dialog() {
    double bredde;
    double lengde;
    printf("Oppgi bredde paa rektangel: ");
    scanf("%lf", &bredde);
    printf("\n");
    printf("Oppgi lengde paa rektangel: ");
    scanf("%lf", &lengde);
    printf("\n");
    double areal = rektangel_areal(bredde, lengde);
    printf("Arealet til rektangelet er: %.2f\n", areal);
    double omkrets = rektangel_omkrets(bredde, lengde);
    printf("Omkretsel til rektangelet er: %.2f\n", omkrets);
}

void sirkel_dialog() {
    double radius;
    printf("Oppgi radius paa sirkel: ");
    scanf("%lf", &radius);
    printf("\n");
    double areal = sirkel_areal(radius);
    printf("Arealet til sirkelen er: %.2f\n", areal);
    double omkrets = sirkel_omkrets(radius);
    printf("Omkretsel til sirkelen er: %.2f\n", omkrets);
}
