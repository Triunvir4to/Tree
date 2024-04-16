#include <iostream>
#include "Tree.h"

int main() {
    Tree *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9;
    a9 = newTree(33, nullptr, nullptr);
    a8 = newTree(42, nullptr, nullptr);
    a7 = newTree(8, nullptr, nullptr);
    a6 = newTree(7, nullptr, a9);
    a5 = newTree(30, nullptr, nullptr);
    a4 = newTree(15, a7, a8);
    a3 = newTree(5, a5, a6);
    a2 = newTree(20, a4, nullptr);
    a1 = newTree(10, a2, a3);

    printTree(a1);

    return 0;
}