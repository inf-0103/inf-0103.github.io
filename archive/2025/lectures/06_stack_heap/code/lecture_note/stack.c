#include <stdio.h>

char STACK[123];
int top = 0;

void push(char ch) {
  STACK[top] = ch;
  top++;
}

char pop() {
  top--;
  return STACK[top];
}

int main() {
  push(1);
  push(2);
  push(3);

  printf("%d", pop());
  printf("%d", pop());
  printf("%d", pop());
}
