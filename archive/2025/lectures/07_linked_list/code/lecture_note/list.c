#include <stdio.h>
#include <stdlib.h>


typedef struct node node_t;
struct node {
  int item;
  node_t *next;
};

node_t *my_list = NULL;

void print_list(node_t *list) {
  printf("[");
  for (node_t *current = list; current != NULL; current = current->next) {
    printf("%d, ", current->item);
  }
  printf("]\n");
}

void add_first(int item) {
  node_t *newnode = malloc(sizeof(node_t));
  newnode->item = item;

  newnode->next = my_list;
  my_list = newnode;
}

// i. hvordan tror vi lister fungerer?
// ii. lenket liste: struktur    [ | ]->[ | ]->||
// iii. legge til noe i lista: først/sist
// iv. legge til noe i lista: i midten
// v. fjerne noe fra lista: først, sist, i midten
int main() {

  add_first(1);
  add_first(2);

  print_list(my_list);

  // legge til midt i
  node_t *current = my_list;
  node_t *newnode = malloc(sizeof(node_t));

  newnode->item = 7;
  current->next = newnode;
  newnode->next = current->next;

  print_list(my_list);

}


//  mylist = [1, 2, 3]
//  mylist.append(4)
