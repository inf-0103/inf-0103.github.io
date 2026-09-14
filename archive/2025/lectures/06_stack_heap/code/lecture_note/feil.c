#include <stdio.h>

int *dobbel(int n) {
  int resultat = 2*n;
  return &resultat;
}

// i. blir dette rett? hvorfor/hvorfor ikke?
//
// ii. kan vi lure programmet til å endre oppførsel uten å endre dobbel()?
int main() {
  int n = 15;
  int *to_n = dobbel(n);

  printf("hei\n");

  printf("to ganger %d er %d\n", n, *to_n);
}
