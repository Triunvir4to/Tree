#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef struct tree {
    int info;
    struct tree *leftNode, *rightNode;
}Tree;

Tree *newTree(int value, Tree *leftNode, Tree *rightNode);
void setNode(Tree *node, int value, Tree *leftNode, Tree *rightNode);
void printTree(Tree *tree);


#endif
