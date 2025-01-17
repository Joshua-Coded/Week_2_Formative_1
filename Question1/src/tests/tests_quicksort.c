#include "../include/student.h"
#include <assert.h>
#include <time.h>

// Test if array is sorted in ascending order
int isSorted(Student arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i-1].grade > arr[i].grade) {
            return 0;
        }
    }
    return 1;
}

// Test Case 1: Basic sorting functionality
void test_basic_sorting() {
    printf("\nTest 1: Basic Sorting Test\n");
    Student students[] = {
        {"John", "Doe", 85.5},
        {"Jane", "Smith", 92.0},
        {"Bob", "Johnson", 78.5}
    };
    int size = 3;
    
    quickSort(students, 0, size - 1);
    
    assert(isSorted(students, size));
    assert(students[0].grade == 78.5);
    assert(students[2].grade == 92.0);
    printf("✓ Basic sorting test passed\n");
}

// Test Case 2: Already sorted array
void test_sorted_array() {
    printf("\nTest 2: Already Sorted Array Test\n");
    Student students[] = {
        {"A", "Student", 75.0},
        {"B", "Student", 85.0},
        {"C", "Student", 95.0}
    };
    int size = 3;
    
    quickSort(students, 0, size - 1);
    assert(isSorted(students, size));
    printf("✓ Already sorted array test passed\n");
}

// Test Case 3: Reverse sorted array
void test_reverse_sorted() {
    printf("\nTest 3: Reverse Sorted Array Test\n");
    Student students[] = {
        {"A", "Student", 95.0},
        {"B", "Student", 85.0},
        {"C", "Student", 75.0}
    };
    int size = 3;
    
    quickSort(students, 0, size - 1);
    assert(isSorted(students, size));
    printf("✓ Reverse sorted array test passed\n");
}

// Test Case 4: Array with duplicate grades
void test_duplicate_grades() {
    printf("\nTest 4: Duplicate Grades Test\n");
    Student students[] = {
        {"John", "Doe", 85.5},
        {"Jane", "Smith", 85.5},
        {"Bob", "Johnson", 92.0},
        {"Alice", "Brown", 92.0}
    };
    int size = 4;
    
    quickSort(students, 0, size - 1);
    assert(isSorted(students, size));
    printf("✓ Duplicate grades test passed\n");
}

// Test Case 5: Single element array
void test_single_element() {
    printf("\nTest 5: Single Element Array Test\n");
    Student students[] = {{"John", "Doe", 85.5}};
    quickSort(students, 0, 0);
    assert(students[0].grade == 85.5);
    printf("✓ Single element array test passed\n");
}

// Test Case 6: Large array performance test
void test_large_array_performance() {
    printf("\nTest 6: Large Array Performance Test\n");
    const int size = 100;
    Student* students = malloc(size * sizeof(Student));
    
    // Initialize with random grades
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        sprintf(students[i].firstName, "Student");
        sprintf(students[i].lastName, "%d", i);
        students[i].grade = (float)(rand() % 10000) / 100; // Random grade between 0-100
    }
    
    clock_t start = clock();
    quickSort(students, 0, size - 1);
    clock_t end = clock();
    
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    assert(isSorted(students, size));
    printf("✓ Large array test passed (Time taken: %f seconds)\n", cpu_time_used);
    
    free(students);
}

// Test Case 7: File I/O test
void test_file_operations() {
    printf("\nTest 7: File I/O Test\n");
    const char* test_file = "test_students.txt";
    const char* output_file = "test_sorted.txt";
    
    // Create test file
    FILE* file = fopen(test_file, "w");
    assert(file != NULL);
    fprintf(file, "John Doe 85.5\nJane Smith 92.0\nBob Johnson 78.5\n");
    fclose(file);
    
    // Test reading
    Student students[100];
    int count = readStudents(test_file, students);
    assert(count == 3);
    
    // Test sorting and writing
    quickSort(students, 0, count - 1);
    writeStudents(output_file, students, count);
    
    // Verify output file
    Student sorted_students[100];
    int sorted_count = readStudents(output_file, sorted_students);
    assert(sorted_count == count);
    assert(isSorted(sorted_students, sorted_count));
    
    // Clean up test files
    remove(test_file);
    remove(output_file);
    
    printf("✓ File I/O test passed\n");
}

// Test Case 8: Error handling test
void test_error_handling() {
    printf("\nTest 8: Error Handling Test\n");
    Student students[100];
    
    // Test non-existent file
    int count = readStudents("nonexistent_file.txt", students);
    assert(count == -1);
    
    printf("✓ Error handling test passed\n");
}

int main() {
    printf("Starting QuickSort Test Suite\n");
    printf("=============================\n");
    
    // Run all tests
    test_basic_sorting();
    test_sorted_array();
    test_reverse_sorted();
    test_duplicate_grades();
    test_single_element();
    test_large_array_performance();
    test_file_operations();
    test_error_handling();
    
    printf("\nAll tests passed successfully!\n");
    return 0;
}
