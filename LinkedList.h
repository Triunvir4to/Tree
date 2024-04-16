#ifndef TAD_LINKEDLIST_H
#define TAD_LINKEDLIST_H

#include "Tree.h"

typedef struct list {
    Tree *info;
    struct list *prox;
}LinkedList;

/**
 * Creates a new LinkedList
 * @return nullptr
 */
LinkedList *newLinkedList();

/**
 * insert a value in a given list
 * @param list  the start of list to include the value
 * @param value the value to be included on the list
 * @return the list with the inserted value
 */
LinkedList *listInsert(LinkedList *list, Tree *value);

/**
 * delete a value in a given list
 * @param list  the start of list to delete the value
 * @param value  the value to be deleted on the list
 * @return the list with the deleted value
 */
LinkedList *listDelete(LinkedList *list, Tree *value);


/**
 * find a value in a given list
 * @param list  the start of list to find the value
 * @param value the value to be finded on the list
 * @return the list on the finded value if nullptr the value was not found
 */
LinkedList *listFind(LinkedList *list, Tree *value);

/**
 * prints an entire list
 * @param list the list to be printed
 */
void listPrint(LinkedList *list);

/**
 * remove memory occupied of a list
 * @param list the list to be freed
 */
void listDestroy(LinkedList *list);

#endif //TAD_LINKEDLIST_H
