#ifndef STUDENT_BST_H
#define STUDENT_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME 50

// Structure for student data
typedef struct Student {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    float grade;
} Student;

// Structure for BST node
typedef struct BSTNode {
    Student data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function declarations
BSTNode* createNode(Student student);
BSTNode* insertNode(BSTNode* root, Student student);
BSTNode* searchByLastName(BSTNode* root, const char* lastName);
void inorderTraversal(BSTNode* root);
void freeBST(BSTNode* root);
BSTNode* buildBSTFromFile(const char* filename);
int compareLastNames(const char* name1, const char* name2);
void displayTreeStats(BSTNode* root);

#endif // STUDENT_BST_H
