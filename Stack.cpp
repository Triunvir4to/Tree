#include <cstdlib>
#include "Stack.h"
#include "LinkedList.h"

Stack *newStack() {
    auto *p = (Stack *) malloc(sizeof(Stack));
    p->n = 0;
    p->list = newLinkedList();
    return p;
}

void stackPush(Stack *p, Tree *v) {
    p->list = listInsert(p->list, v);
    ++p->n;
}

Tree *stackPop(Stack *p) {
    if (stackEmpty(p))
        throw ("Empty stack");

    --p->n;
    Tree *value;
    LinkedList *iterator;
    for (iterator = p->list;; iterator = iterator->prox)
        if (iterator->prox == nullptr) {
            value = iterator->info;
            listDelete(p->list, iterator->info);
            break;
        }
    return value;
}

bool stackEmpty(Stack *p) {
    return p->n == 0;
}

Stack *stackConcat(Stack *stack1, Stack *stack2) {
    Stack *temp = newStack();
    while (!stackEmpty(stack1))
        stackPush(temp, stackPop(stack1));

    while (!stackEmpty(temp))
        stackPush(stack2, stackPop(temp));

    stackDestroy(temp);
    return stack2;
}

Stack *stackCopy(Stack *stack) {
    Stack *temp = stackConcat(stack, newStack());
    return temp;
}

Tree *stackTop(Stack *stack) {
    Tree *value = stackPop(stack);
    stackPush(stack, value);
    return value;
}


void stackDestroy(Stack *p) {
    listDestroy(p->list);
    free(p);
}
