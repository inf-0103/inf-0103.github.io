#include <stdio.h>
#include <stdlib.h>

// virker på apple arm64, andre maskiner har annen assembly
void *return_address() {
  void* return_address;
  asm("mov %0, x30" : "=r"(return_address));
  return return_address;
}

// i. hvor ligger stack?
// ii. hvor ligger heap?
// iii. hvor ligger main?
int main() {
  char stack = 2;
  char *heap = malloc(sizeof(char));
  
  void *main_addresse = return_address();

  printf("avstand mellom stack og heap: %ld\n", &stack - heap);
  printf("avstand mellom stack og main(): %ld\n", &stack - (char *)main_addresse);

  return 0;
}
