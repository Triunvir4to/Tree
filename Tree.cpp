#include "Tree.h"
#include <cstdlib>
#include <cstdio>
#include "Stack.h"

Tree *newTree(int value, Tree *leftNode, Tree *rightNode) {
    Tree *newTree = (Tree *) malloc(sizeof(Tree));
    setNode(newTree, value, leftNode, rightNode);
    return newTree;
}

void setNode(Tree *node, int value, Tree *leftNode, Tree *rightNode) {
    if (node == nullptr) return;
    node->info = value;
    node->leftNode = leftNode;
    node->rightNode = rightNode;
}

void printTree(Tree *tree) {
    if (tree == nullptr)return;

    Stack *stack = newStack();
    stackPush(stack, tree);

    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack);

        printf("%d\n", node->info);

        if (node->rightNode != nullptr)
            stackPush(stack, node->rightNode);
        if (node->leftNode != nullptr)
            stackPush(stack, node->leftNode);
    }
}
