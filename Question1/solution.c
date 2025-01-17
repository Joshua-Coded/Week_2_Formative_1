/**
* Purpose: Create a program that uses a quick sort algorithms to sort out the records in ascending order based on  grades, the program shall record the sorted data in a new file

* Author: Joshua Alana
* Date Created: 17/01/2025
*/

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


// Function to swap two students

void swap(Student* a, Student* b){
	Student temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function for quiksort

int partition(Student arr[], int low, int high){
    float pivot = arr[high].grade; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
	if (arr[j].grade <= pivot) {
	  i++;
	  swap(&arr[i], &arr[j]);
}
}

swap(&arr[i + 1], &rr[high]);
return (i + 1);
}

// QuickSort function

void quickSort(Student arr[], int low, int high){
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
   while (fscanf(file, "%s %s %f", students[count].firstName, students[count].lastName, &students[count].grade) == 3) {
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
    fprintf(file, "%s %s %.2f\n", students[i].firstName, students[i].lastName, students[i].grade);
}

fclose(file);
}


int main() {
Student students[100]; // Array to store 100 Students

// Read students from input file
int count = readStudents("input.txt", students);
if (count == -1) return 1;

// Sort students using quicksort
quickSort(students, 0, count - 1);

// Write Sorted students to output file
writeStudents("sorted_output.txt", students);

printf("Sorting completed successfully!\n");
return 0;
}

