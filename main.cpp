#include <iostream>
#include "Tree.h"

int main() {
    Tree *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *copy;
    a9 = newTree(33, nullptr, nullptr);
    a8 = newTree(42, nullptr, nullptr);
    a7 = newTree(8, nullptr, nullptr);
    a6 = newTree(7, nullptr, a9);
    a5 = newTree(30, nullptr, nullptr);
    a4 = newTree(15, a7, a8);
    a3 = newTree(5, a5, a6);
    a2 = newTree(20, a4, nullptr);
    a1 = newTree(10, a2, a3);

    copy = treeCopy(a1);

    printf("1. pares: %d\n", treeGetNumOfPairValues(a1));
    printf("2. Quantidades de folhas: %d\n", treeGetNumofLeaves(a1));
    printf("3. Nos com 1 filho: %d\n", treeGetNumofOneSonNode(a1));
    printf("4. No 1 igual a no 1: %d\n", treeEquals(a1, a2));
    printf("5. No 1 igual a copia: %d\n", treeEquals(a1, copy));

    return 0;
}