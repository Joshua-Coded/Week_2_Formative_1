# Student BST Search Implementation

## Overview
Implementation of a Binary Search Tree (BST) for student records, focusing on searching by last name. This program reads student data from Question1's data file and provides efficient searching capabilities.

## Project Structure
```
.
├── include/
│   └── student_bst.h        # Header file
├── src/
│   └── student_bst/
│       ├── main.c          # Main program
│       └── student_bst.c   # BST implementation
└── Makefile
```

## Time Complexity Analysis

### 1. BST Search Complexity
```
Best/Average Case: O(log n)
- Balanced tree structure
- Each comparison eliminates half of remaining nodes

Worst Case: O(n)
- When tree becomes linear (unbalanced)
- All nodes in a single branch
```

### 2. BST vs Linear Search
- **Linear Search**: O(n)
  - Must search through entire file
  - Always checks every record

- **BST Search**: O(log n)
  - More efficient for large datasets
  - Requires initial tree construction

### 3. When to Use Each Method
- **Use Linear Search When**:
  - Small dataset (< 100 records)
  - One-time search needed
  - Memory is limited

- **Use BST When**:
  - Large dataset
  - Multiple searches needed
  - Memory available for tree structure

## BST vs Binary Tree
1. **BST**:
   - Ordered structure (left < node < right)
   - Efficient searching O(log n)
   - Self-organizing data structure

2. **Binary Tree**:
   - No ordering requirement
   - Linear search time O(n)
   - General-purpose tree structure

## Build and Run

### Compile
```bash
make clean
make all
```

### Run
```bash
./build/student_bst
```

## Features
1. Search by last name
2. Display sorted student list
3. Tree statistics display
4. Memory management
5. Error handling

## Implementation Details
- Uses parent student data from Question1
- Focuses on last name for BST organization
- Includes comprehensive error checking
- Provides tree statistics

## Sample Output
```
Student BST Operations
=====================
1. Search by Last Name
2. Display All Students (Sorted)
3. Exit

Enter your choice: 2
Students in alphabetical order:
Anderson, William: 83.60
Brown, Sarah: 95.20
Davis, James: 88.70
...
```
