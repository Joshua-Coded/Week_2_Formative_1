#include "../../include/student_bst.h"

// Create new BST node
BSTNode* createNode(Student student) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = student;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Compare last names for BST ordering
int compareLastNames(const char* name1, const char* name2) {
    if (!name1 || !name2) return 0;
    return strcmp(name1, name2);
}

// Insert node into BST
BSTNode* insertNode(BSTNode* root, Student student) {
    // If tree is empty, create root node
    if (root == NULL) {
        return createNode(student);
    }
    
    // Compare last names to determine insertion position
    int comparison = compareLastNames(student.lastName, root->data.lastName);
    
    if (comparison < 0) {
        root->left = insertNode(root->left, student);
    } else if (comparison > 0) {
        root->right = insertNode(root->right, student);
    } else {
        // Handle duplicate: Update grade if same last name
        root->data.grade = student.grade;
    }
    
    return root;
}

// Search BST by last name
BSTNode* searchByLastName(BSTNode* root, const char* lastName) {
    // Validate input
    if (!lastName) {
        printf("Invalid search input!\n");
        return NULL;
    }
    
    // Base cases: root is null or last name matches
    if (root == NULL || strcmp(root->data.lastName, lastName) == 0) {
        return root;
    }
    
    // Recursively search appropriate subtree
    if (strcmp(lastName, root->data.lastName) < 0) {
        return searchByLastName(root->left, lastName);
    }
    return searchByLastName(root->right, lastName);
}

// Build BST from file
BSTNode* buildBSTFromFile(const char* filename) {
    if (!filename) {
        printf("Invalid filename!\n");
        return NULL;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    
    BSTNode* root = NULL;
    Student student;
    char line[256];
    int lineNum = 0;
    
    while (fgets(line, sizeof(line), file)) {
        lineNum++;
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        if (sscanf(line, "%s %s %f", student.firstName, student.lastName, 
                   &student.grade) == 3) {
            // Validate grade
            if (student.grade < 0 || student.grade > 100) {
                printf("Warning: Invalid grade on line %d: %.2f\n", lineNum, student.grade);
                continue;
            }
            root = insertNode(root, student);
        } else {
            printf("Warning: Invalid format on line %d: %s\n", lineNum, line);
        }
    }
    
    fclose(file);
    return root;
}

// In-order traversal for sorted output
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%-20s %-20s %.2f\n", 
               root->data.lastName, 
               root->data.firstName, 
               root->data.grade);
        inorderTraversal(root->right);
    }
}

// Get height of the tree
int getTreeHeight(BSTNode* root) {
    if (root == NULL) return 0;
    
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes in the tree
int countNodes(BSTNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Display tree statistics
void displayTreeStats(BSTNode* root) {
    printf("\nBST Statistics:\n");
    printf("===============\n");
    printf("Total nodes: %d\n", countNodes(root));
    printf("Tree height: %d\n", getTreeHeight(root));
    
    // Calculate theoretical minimum height for perfect balance
    int minHeight = (int)ceil(log2(countNodes(root) + 1));
    printf("Minimum possible height: %d\n", minHeight);
}

// Free BST memory
void freeBST(BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}
