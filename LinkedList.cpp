#include <cstdlib>
#include <cstdio>
#include "LinkedList.h"

LinkedList *newLinkedList() { return nullptr; }

LinkedList *listInsert(LinkedList *list, Tree *value) {
    auto *newElement = (LinkedList *) malloc(sizeof(LinkedList));
    newElement->prox = nullptr;
    newElement->info = value;

    if (list == nullptr)
        return newElement;


    LinkedList *iterator = list;
    while (iterator->prox != nullptr)
        iterator = iterator->prox;

    iterator->prox = newElement;

    return list;
}

LinkedList *listDelete(LinkedList *list, Tree *value) {
    if (list == nullptr)
        return nullptr;

    LinkedList *iterator = list, *temp;

    if (iterator->info == value) {
        list = list->prox;
        iterator = nullptr;
        free(iterator);
        return list;
    }

    while (iterator->prox != nullptr && iterator->prox->info != value)
        iterator = iterator->prox;

    if (iterator->prox != nullptr) {
        temp = iterator->prox;
        iterator->prox = temp->prox;
        temp = nullptr;
        free(temp);
    }

    return list;
}


LinkedList *listFind(LinkedList *list, Tree *value) {
    for (LinkedList *iterator = list; iterator != nullptr; iterator = iterator->prox)
        if (iterator->info == value)
            return iterator;

    return nullptr;
}

void listPrint(LinkedList *list) {
    for (LinkedList *iterator = list; iterator != nullptr; iterator = iterator->prox)
        printf("%d ", iterator->info->info);
}

void listDestroy(LinkedList *list) {
    LinkedList *iterator = list;
    while (iterator != nullptr) {
        auto temp = iterator;
        iterator = iterator->prox;
        free(temp);
    }
}