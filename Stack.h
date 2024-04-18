#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "LinkedList.h"
#include "Tree.h"

typedef struct stack {
    int n;
    LinkedList *list;
} Stack;

/**
 * @brief Creates a new stack and initializes its properties.
 *
 * This function dynamically allocates memory for a new Stack instance,
 * initializes its size (n) to 0, and creates a new linked list to represent
 * the stack's underlying storage.
 *
 * @return Pointer to the newly created Stack.
 */
Stack *newStack();

/**
 * @brief Adds a new element to the top of the stack.
 *
 * This function inserts a new element at the beginning of the stack's
 * linked list, effectively pushing it onto the stack. It also increments
 * the stack's size counter.
 *
 * @param stack Pointer to the Stack to which the element is to be added.
 * @param v The value to be pushed onto the stack.
 */
void stackPush(Stack *stack, Tree *v);

/**
 * @brief Removes and returns the top element of the stack.
 *
 * This function removes the element at the beginning of the stack's
 * linked list, effectively popping it from the stack. It decrements
 * the stack's size counter. If the stack is empty, it throws an exception.
 *
 * @param stack Pointer to the Stack from which the element is to be removed.
 * @return The value that was removed from the stack.
 * @throws const char* If the stack is empty.
 */
Tree *stackPop(Stack *stack);

/**
 * @brief Checks if the stack is empty.
 *
 * This function determines whether the stack is empty by checking if
 * the stack's size counter is zero.
 *
 * @param stack Pointer to the Stack to be checked.
 * @return True if the stack is empty, false otherwise.
 */
bool stackEmpty(Stack *stack);

/**
 * @brief Concatenates two stacks into one.
 *
 * This function moves all elements from stack1 and stack2 into stack2,
 * leaving stack1 empty. The elements are moved in such a way that the
 * order is preserved in the resultant stack2.
 *
 * @param stack1 Pointer to the first Stack.
 * @param stack2 Pointer to the second Stack.
 * @return Pointer to the modified second Stack containing all elements.
 */
Stack *stackConcat(Stack *stack1, Stack *stack2);

/**
 * @brief Creates a copy of the given stack.
 *
 * This function creates a new stack and copies all elements from the
 * original stack into the new stack, preserving the order.
 *
 * @param stack Pointer to the Stack to be copied.
 * @return Pointer to the newly created Stack that is a copy of the original.
 */
Stack *stackCopy(Stack *stack);

/**
 * @brief Retrieves the top element of the stack without removing it.
 *
 * This function peeks at the top element of the stack by temporarily
 * removing it to get its value, then pushes it back onto the stack.
 *
 * @param stack Pointer to the Stack.
 * @return The value at the top of the stack.
 * @throws const char* If the stack is empty.
 */
Tree *stackTop(Stack *stack);

/**
 * @brief Destroys the stack and releases allocated memory.
 *
 * This function deallocates the memory used by the stack's linked list
 * and then frees the memory allocated for the stack itself, effectively
 * destroying the stack.
 *
 * @param stack Pointer to the Stack to be destroyed.
 */
void stackDestroy(Stack *stack);


#endif //STACK_STACK_H
