#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/*
 * No actual tests are contained in this file. They are
 * all written in a file that will not be distributed to
 * students because it would easily let them reverse engineer
 * a solution without really understanding the problem.
 *
 * The real tests are mostly wrappers around list functions:
 * they call the functions (passing along any arguments)
 * and verify the results before returning.
 */

/* List is printed in the following format:
 * (head) X -> Y -> :( -> Z
 * X, Y and Z are integers and:
 * X is the value at the head of the list
 * Y is a node with a valid value
 * The frowny face is a valid node with an invalid item pointer
 * Z is another node with a valid value
 */
void test_list();
void test_iterator();
void print_list(list_t *list);

list_t *test_list_create(void);
void test_list_size(void);
void test_list_addfirst(list_t *list, int *item);
void test_list_addlast(list_t *list, int *item);
void test_list_remove(list_t *list, int *item);
list_iterator_t *test_list_createiterator(list_t *list);
void test_list_next(list_iterator_t *iter);
void test_list_resetiterator(list_iterator_t *iter);
list_t *test_iterator_setup_list(void);
void test_iterator_verify_data(void);
void test_iterator_cleanup_list(list_t *list);
void test_list_next(list_iterator_t *iter);
 
int main()
{
    // Disable output buffering
    setbuf(stdout, NULL);
    
    test_list();
    test_iterator();

    printf("\nYour list implementation looks OK!\n");

    return 0;
}

void test_list()
{
    // Make sure create works:
    printf("\nlist_create:\t");
    list_t *list = test_list_create();
    printf("OK\n");


    printf("list_destroy:\t");
    list_destroy(list);
    printf("OK\n");

    // All of our items
    int *two_squared = malloc(sizeof(int));
    *two_squared = 4;

    int *three_squared = malloc(sizeof(int));
    *three_squared = 9;

    int *four_squared = malloc(sizeof(int));
    *four_squared = 16;

    int *five_squared = malloc(sizeof(int));
    *five_squared = 25;

    // Make sure addfirst works:
    printf("list_addfirst:\t");
    list = list_create();
    // Special case: empty list
    test_list_addfirst(list, three_squared);
    // General case
    test_list_addfirst(list, two_squared);
    list_destroy(list);
    printf("OK\n");

    // Trivial, but make sure list_size works
    printf("list_size:\t");
    test_list_size();
    printf("OK\n");

    // Make sure addlast works:
    printf("list_addlast:\t");
    list = list_create();
    // Special case: empty list
    test_list_addlast(list, four_squared);
    // General case
    test_list_addlast(list, five_squared);
    list_destroy(list);
    printf("OK\n");

    // Make sure remove works:
    printf("list_remove:\t");
    list = list_create();
    list_addfirst(list, three_squared);
    list_addfirst(list, two_squared);
    list_addlast(list, four_squared);
    list_addlast(list, five_squared);
    // General case: Item in middle of list
    test_list_remove(list, four_squared);
    // General case: Item at then end of list
    test_list_remove(list, five_squared);
    // Special case: Item at the head of list
    test_list_remove(list, two_squared);
    list_destroy(list);
    printf("OK\n\n");

}

void test_iterator()
{
    list_t *list = test_iterator_setup_list();

    // Test iterator creation
    printf("list_createiterator:\t");
    list_iterator_t *iter = test_list_createiterator(list);
    printf("OK\n");

    // Test getting next item from list
    printf("list_next:\t\t");
    test_list_next(iter);
    printf("OK\n");

    // Test resetting the iterator
    printf("list_resetiterator:\t");
    test_list_resetiterator(iter);
    test_list_next(iter);
    printf("OK\n");

    // Test the destruction of the iterator
    printf("list_destroyiterator:\t");
    list_destroyiterator(iter);
    printf("OK\n");

    // Test to make sure that the data is untouched
    test_iterator_verify_data();
    test_iterator_cleanup_list(list);

    return;
}
