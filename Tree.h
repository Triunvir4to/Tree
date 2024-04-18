#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef struct tree {
    int info;
    struct tree *leftNode, *rightNode;
}Tree;

Tree *newTree(int value, Tree *leftNode, Tree *rightNode);
void setNode(Tree *node, int value, Tree *leftNode, Tree *rightNode);
void treePrint(Tree *tree);
int treeEquals(Tree *tree1, Tree * tree2);
int treeGetNumOfPairValues(Tree *tree);
int treeGetNumofLeaves(Tree *tree);
int treeGetNumofOneSonNode(Tree *tree);



#endif
