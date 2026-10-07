#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * List implementation
 */

typedef struct listnode listnode_t;

struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};

/*
 * Returns a newly created, empty list.
 */
list_t *list_create(void)
{
    /* Allocate memory */
    list_t *list = malloc(sizeof(list_t));
    if(!list)
        return NULL;

    /* Initialize empty list */
    list->head = NULL;
    list->numitems = 0;

    return list;
}

/*
 * Frees the list; list and nodes, but not the items it holds.
 */
void list_destroy(list_t *list)
{
    listnode_t *tmp = list->head;

    /* Iterate over the list, freeing each node */
    while(list->head) {
        tmp = list->head;
        list->head = tmp->next;

        free(tmp);
    }
    free(list);
}

/*
 * Adds an item first in the provided list.
 */
void list_addfirst(list_t *list, void *item)
{
    /* Allocate memory, and have a bad null check */
    listnode_t *node = malloc(sizeof(listnode_t));
    if(!node) {
        return;
    }
    
    /* Initialize the node  */
    node->item = item;
    node->next = list->head;

    /* Update the list */
    list->head = node;
    list->numitems++;
}

/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item)
{
    listnode_t *new_node = (listnode_t*)malloc(sizeof(listnode_t));
    if (new_node == NULL)
        return;

    /* Initialize the node */
    new_node->item = item;
    new_node->next = NULL;

    listnode_t *currentnode = list->head;
    if(currentnode == NULL) // What if the list is empty?
    {
        list->head = new_node;
    }
    else
    {
        // The last node in the linked list will be the one before NULL
        while(currentnode->next != NULL)
            currentnode = currentnode->next;

        currentnode->next = new_node;
    }

    list->numitems++;
}

/*
 * Removes an item from the provided list, only freeing the node.
 */
void list_remove(list_t *list, void *item)
{
    /* If the list is empty, don't do anything */
    if(list->numitems == 0)
        return;

    listnode_t *tmp = list->head,
               *prev = NULL;

    /* Iterate over the list, freeing the node if found */
    while(tmp) {
        if(tmp->item == item) {
            if(prev)
                prev->next = tmp->next;
            else
                list->head = tmp->next;
            free(tmp);
            list->numitems--;

            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

/*
 * Return the number of items in the list.
 */
int list_size(list_t *list)
{
    return list->numitems;
}



/*
 * Iterator implementation
 */
 

struct list_iterator {
    listnode_t *next;
    list_t *list;
};


/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list)
{
    /* Allocate memory */
    list_iterator_t *iter = malloc(sizeof(list_iterator_t));
    if(!iter)
        return NULL;

    /* Initialize the iterator */
    iter->list = list;
    iter->next = list->head;

    return iter;
}


/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter)
{
    free(iter);
}


/*
 * Move iterator to next item in list and return current.
 * Return NULL if at end of list
 */
void *list_next(list_iterator_t *iter)
{
    listnode_t *tmp = iter->next;

    /* Return the current item if not at the end of the list, or NULL if at end*/
    if(tmp) {
        iter->next = tmp->next;
        return tmp->item;
    }
    return NULL;
}


/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter)
{
    iter->next = iter->list->head;
}
