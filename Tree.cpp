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

void getNodeLeaves(Stack *stack, Tree *insertValue) {
    if (insertValue->rightNode != nullptr)
        stackPush(stack, insertValue->rightNode);
    if (insertValue->leftNode != nullptr)
        stackPush(stack, insertValue->leftNode);
}

void treePrint(Tree *tree) {
    if (tree == nullptr)return;

    Stack *stack = newStack();
    stackPush(stack, tree);

    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack);

        printf("%d\n", node->info);

        getNodeLeaves(stack, node);
    }
    stackDestroy(stack);
}


int treeEquals(Tree *tree1, Tree *tree2) {
    if (tree1 == nullptr && tree2 == nullptr)
        return 1;

    Stack *stackTree1 = newStack();
    stackPush(stackTree1, tree1);
    Stack *stackTree2 = newStack();
    stackPush(stackTree2, tree2);

    while (!stackEmpty(stackTree1) && !stackEmpty(stackTree2)) {
        Tree *node1 = stackPop(stackTree1);
        Tree *node2 = stackPop(stackTree2);

        if (node1->info != node2->info)
            return 0;

        getNodeLeaves(stackTree1, node1);
        getNodeLeaves(stackTree2, node2);

    }

    stackDestroy(stackTree1);
    stackDestroy(stackTree2);

    return 1;
}

Tree *treeCopy(Tree *tree) {
    Tree *tree1 = nullptr;
    Stack *stack = newStack();
    stackPush(stack, tree);
    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack), *it = newTree(node->info, node->leftNode, node->rightNode);
        if (tree1 == nullptr)
            tree1 = it;
        getNodeLeaves(stack, node);
    }

    return tree1;
}

int treeGetNumOfPairValues(Tree *tree) {
    Stack *stack = newStack();
    stackPush(stack, tree);

    int counter = 0;

    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack);

        counter += node->info % 2 == 0 ? 1 : 0;

        getNodeLeaves(stack, node);
    }

    stackDestroy(stack);

    return counter;
}

int treeGetNumofLeaves(Tree *tree) {
    Stack *stack = newStack();
    stackPush(stack, tree);

    int counter = 0;

    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack);

        if (node->rightNode == nullptr && node->leftNode == nullptr)
            ++counter;

        if (node->rightNode != nullptr)
            stackPush(stack, node->rightNode);
        if (node->leftNode != nullptr)
            stackPush(stack, node->leftNode);
    }

    stackDestroy(stack);

    return counter;
}

int treeGetNumofOneSonNode(Tree *tree) {
    Stack *stack = newStack();
    stackPush(stack, tree);

    int counter = 0;

    while (!stackEmpty(stack)) {
        Tree *node = stackPop(stack);

        if ((node->rightNode == nullptr && node->leftNode != nullptr) ||
            (node->leftNode == nullptr && node->rightNode != nullptr))
            ++counter;

        if (node->rightNode != nullptr)
            stackPush(stack, node->rightNode);
        if (node->leftNode != nullptr)
            stackPush(stack, node->leftNode);
    }

    return counter;
}