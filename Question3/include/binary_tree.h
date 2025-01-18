#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;  // Added parent pointer for easier navigation
} Node;

// Function declarations
Node* createNode(int value);
Node* buildTree(int arr[], int size);
Node* findNode(Node* root, int value);
void getLeafNodes(Node* root);
Node* getSibling(Node* node);
void getGrandchildren(Node* node);
void freeTree(Node* root);
void displayTree(Node* root, int level);

#endif // BINARY_TREE_H
