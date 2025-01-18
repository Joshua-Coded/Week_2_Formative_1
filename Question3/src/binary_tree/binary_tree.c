#include "../../include/binary_tree.h"

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Build binary tree from array
Node* buildTree(int arr[], int size) {
    if (size <= 0) return NULL;
    
    // Create root node
    Node* root = createNode(arr[0]);
    
    // Queue for level order insertion
    Node* queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    // Insert rest of the nodes level by level
    int i = 1;
    while (i < size) {
        Node* current = queue[front++];
        
        // Insert left child
        if (i < size) {
            current->left = createNode(arr[i]);
            current->left->parent = current;
            queue[rear++] = current->left;
            i++;
        }
        
        // Insert right child
        if (i < size) {
            current->right = createNode(arr[i]);
            current->right->parent = current;
            queue[rear++] = current->right;
            i++;
        }
    }
    
    return root;
}

// Find node with given value
Node* findNode(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    
    Node* leftResult = findNode(root->left, value);
    if (leftResult != NULL)
        return leftResult;
        
    return findNode(root->right, value);
}

// Print all leaf nodes
void getLeafNodes(Node* root) {
    if (root == NULL)
        return;
        
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    
    getLeafNodes(root->left);
    getLeafNodes(root->right);
}

// Get sibling of a node
Node* getSibling(Node* node) {
    if (node == NULL || node->parent == NULL)
        return NULL;
        
    if (node->parent->left == node)
        return node->parent->right;
    return node->parent->left;
}

// Get grandchildren of a node
void getGrandchildren(Node* node) {
    if (node == NULL) return;
    
    // Check left child's children
    if (node->left) {
        if (node->left->left)
            printf("%d ", node->left->left->data);
        if (node->left->right)
            printf("%d ", node->left->right->data);
    }
    
    // Check right child's children
    if (node->right) {
        if (node->right->left)
            printf("%d ", node->right->left->data);
        if (node->right->right)
            printf("%d ", node->right->right->data);
    }
}

// Free the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Display tree structure
void displayTree(Node* root, int level) {
    if (root == NULL) return;
    
    displayTree(root->right, level + 1);
    
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data);
    
    displayTree(root->left, level + 1);
}
