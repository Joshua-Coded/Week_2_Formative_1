#include "../../include/student.h"

int main() {
    Student students[100];  // Array to store 100 students
    
    // Read students from input file
    int count = readStudents("data/students.txt", students);
    if (count == -1) {
        printf("Error: Could not read input file\n");
        return 1;
    }
    
    printf("Read %d students from file\n", count);
    
    // Sort students using quicksort
    quickSort(students, 0, count - 1);
    
    // Write sorted students to output file
    writeStudents("data/sorted_students.txt", students, count);
    
    printf("Sorting completed successfully!\n");
    return 0;
}
