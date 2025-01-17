# Data Structures and Algorithms - Assignment Solution

## Question 1: Quick Sort Implementation for Student Records

### Program Overview
The program implements a quick sort algorithm to sort student records based on their grades. It reads from an input file containing student information (first name, last name, and grade), sorts the records in ascending order based on grades, and writes the sorted data to a new output file.

### Implementation Details

#### 1. Data Structure
```c
typedef struct {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    float grade;
} Student;
```

#### 2. Key Functions
- `readStudents()`: Reads student records from input file
- `quickSort()`: Implements the sorting algorithm
- `partition()`: Handles array partitioning for quicksort
- `writeStudents()`: Writes sorted records to output file

### Time Complexity Analysis

#### 1. Mathematical Derivation

The QuickSort algorithm's time complexity can be understood through its recurrence relation:
```
T(n) = T(k) + T(n-k-1) + cn
where:
- n is the input size
- k is the size of the first partition
- c is a constant representing the partitioning work
```

#### 2. Best Case: O(n log n)
When partitions are evenly balanced (k = n/2):
```
Level 0: cn                 (root level)
Level 1: 2(cn/2) = cn      (2 subproblems)
Level 2: 4(cn/4) = cn      (4 subproblems)
...continues for log n levels

Total Work = cn × log n = O(n log n)
```

#### 3. Average Case: O(n log n)
- Partitions may not be exactly equal but remain relatively balanced
- Expected number of levels remains O(log n)
- Each level still processes n elements
- Therefore, average case maintains O(n log n) complexity

#### 4. Worst Case: O(n²)
When we get most unbalanced partitions:
```
T(n) = T(n-1) + cn

Sum of operations:
cn + c(n-1) + c(n-2) + ... + c(1)
= c[n + (n-1) + (n-2) + ... + 1]
= c × n(n+1)/2
= O(n²)
```

### Why QuickSort Over Insertion Sort?

1. **Performance Comparison**
   - For n = 100 students:
     - QuickSort (average): O(n log n) ≈ 100 × log₂(100) ≈ 664 operations
     - Insertion Sort: O(n²) = 100² = 10,000 operations

2. **Practical Advantages**
   - In-place sorting (minimal extra memory required)
   - Better cache performance due to partitioning approach
   - More efficient with random memory access patterns
   - Better scalability for larger datasets

3. **Specific to Our Use Case**
   - Handles student records efficiently
   - Maintains data integrity during sorting
   - Performs well with varied grade distributions
   - Easily adapts to increased dataset size

### Error Handling
- Proper file I/O error checking
- Memory management with fixed-size arrays
- Data validation during read/write operations

### Usage
```bash
# Compile the program
gcc -o student_sort student_sort.c

# Run the program
./student_sort
```

### Input/Output Format
```
# Input file format (input.txt):
FirstName LastName Grade

# Output file format (sorted_output.txt):
FirstName LastName Grade
```

---
