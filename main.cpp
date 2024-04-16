#include <iostream>
#include "Stack.h"

int main() {
    Stack *stack1 = newStack(), *stack2 = newStack();

    for (int i = 0; i < 5; ++i)
        stackPush(stack1, newTree(1 + i, nullptr, nullptr));

    for (int i = 0; i < 5; ++i)
        stackPush(stack2, newTree((1 + i) * 10, nullptr, nullptr));

    stackConcat(stack1, stack2);

    while (!stackEmpty(stack2))
        std::cout << stackPop(stack2) << " ";

    stackDestroy(stack1);
    stackDestroy(stack2);

    return 0;
}