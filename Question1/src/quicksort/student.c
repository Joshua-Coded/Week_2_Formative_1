#include "../../include/student.h"

// Function to swap two students
void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(Student arr[], int low, int high) {
    float pivot = arr[high].grade;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].grade <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to read students from file
int readStudents(const char* filename, Student students[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening input file\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s %f", students[count].firstName, 
                 students[count].lastName, &students[count].grade) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to write sorted students to file
void writeStudents(const char* filename, Student students[], int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening output file\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f\n", students[i].firstName, 
                students[i].lastName, students[i].grade);
    }

    fclose(file);
}
