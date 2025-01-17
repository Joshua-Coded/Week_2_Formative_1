# Student Records Sorting System

## Implementation Details

### 1. QuickSort Algorithm Implementation
The program successfully implements QuickSort with the following components:
```c
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### 2. File Operations
- **Input**: Reads student records from `students.txt`
- **Output**: Writes sorted data to `sorted_output.txt`
- **Format**: `FirstName LastName Grade`

### 3. Data Structure
```c
typedef struct {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    float grade;
} Student;
```

## Running Time Analysis

### Time Complexity Derivation
Given n elements (students), the running time function T(n) is derived as follows:

1. **Partition Function**: 
   - Scans through array: n operations
   - T(n) = cn for constant c

2. **QuickSort Recursion**:
   ```
   T(n) = T(k) + T(n-k-1) + cn
   where k is partition size
   ```

3. **Resolving to Big-O Notation**:
   - Best/Average Case: O(n log n)
     - When partitions are balanced (k ≈ n/2)
     - Log n levels × n operations per level
   - Worst Case: O(n²)
     - When partitions are most unbalanced
     - n levels × n operations per level

## QuickSort vs Insertion Sort Justification

### 1. Performance Comparison
For our dataset (n = 100 students):
- QuickSort (Average): O(n log n) = 100 × log₂(100) ≈ 664 operations
- Insertion Sort: O(n²) = 100² = 10,000 operations

### 2. Dataset Characteristics
QuickSort is better suited because:
- Large dataset (100 students)
- Random grade distribution
- No guarantee of partial ordering

## Project Structure and Building
```
.
├── src/
│   ├── quicksort/
│   │   ├── main.c
│   │   └── student.c
│   └── tests/
├── include/
│   └── student.h
└── data/
    └── students.txt
```

### Build and Run
```bash
make all
./build/quicksort
```

## Sample Output
```
# Input (students.txt):
John Doe 85.5
Jane Smith 92.0
Bob Johnson 78.5

# Output (sorted_output.txt):
Bob Johnson 78.5
John Doe 85.5
Jane Smith 92.0
```

---
