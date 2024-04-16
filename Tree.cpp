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

    Stack *

}
