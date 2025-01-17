#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

// Structure to store student information
typedef struct {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    float grade;
} Student;

// Function declarations
void swap(Student* a, Student* b);
int partition(Student arr[], int low, int high);
void quickSort(Student arr[], int low, int high);
int readStudents(const char* filename, Student students[]);
void writeStudents(const char* filename, Student students[], int count);

#endif // STUDENT_H
