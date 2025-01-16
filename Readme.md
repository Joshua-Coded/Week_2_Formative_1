# Data Structures and Algorithms Project

## Project Overview
This project implements various data structures and algorithms including QuickSort, Doubly Linked Lists, Binary Trees, and Binary Search Trees (BST) in C.

## Project Structure
```
.
├── include/              # Header files
├── src/                  # Source files
│   ├── quicksort/        # Question 1 implementation
│   ├── bus_route/        # Question 2 implementation
│   ├── binary_tree/      # Question 3 implementation
│   └── bst/              # Question 4 implementation
├── data/                 # Data files
│   └── students.txt      # Student records
└── tests/                # Test files
```

## Features

### 1. Student Record Sorting (QuickSort)
- Reads student records from text file
- Implements QuickSort algorithm
- Sorts based on grades in ascending order
- Outputs sorted data to new file
- Time complexity analysis included

### 2. Bus Route Navigation System
- Implements doubly linked list for bus stops
- Forward navigation with 3-second delays
- Backward navigation with 3-second delays
- Auto-stop at terminal points
- Time complexity analysis for operations

### 3. Binary Tree Operations
- Builds binary tree from 20 integers
- Features:
  * Root node retrieval
  * Leaf nodes identification
  * Sibling node finding
  * Parent node lookup
  * Grandchildren retrieval
- Time complexity analysis

### 4. Student BST Implementation
- Creates BST from student records
- Name-based search functionality
- Comparative analysis with linear search
- Time complexity documentation

## Getting Started

### Prerequisites
- GCC Compiler
- Make utility
- Unix-like environment

### Installation
```bash
# Clone the repository
git clone [repository-url]

# Navigate to project directory
cd [project-directory]

# Build all programs
make all
```

### Running the Programs

1. QuickSort Implementation:
```bash
./bin/quicksort data/students.txt
```

2. Bus Route System:
```bash
./bin/bus_route
```

3. Binary Tree Operations:
```bash
./bin/binary_tree
```

4. Student BST:
```bash
./bin/student_bst
```

## Usage Examples

### Student Record Sorting
```c
// Input file format (students.txt):
John Doe 85
Jane Smith 92
...

// Run the program:
./bin/quicksort data/students.txt
```

### Bus Route Navigation
```c
// Example interaction:
Enter direction (F/B): F
Starting route...
Stop 1: Downtown
[3 seconds delay]
Stop 2: University Ave
...
```

### Binary Tree Operations
```c
// Example usage:
Enter node value to find siblings: 15
Siblings of 15: 12, 18
```

### BST Operations
```c
// Example search:
Enter student last name: Smith
Found: Smith, Jane - Grade: 92
```

## Time Complexity Analysis

1. QuickSort:
- Average case: O(n log n)
- Worst case: O(n²)

2. Doubly Linked List:
- Insertion at end: O(1)
- Traversal: O(n)

3. Binary Tree:
- Node insertion: O(h), where h is height
- Searching: O(h)

4. BST:
- Search: O(log n) average case
- Insertion: O(log n) average case

## Authors
[Joshua Alana]

## License
This project is licensed under the MIT License - see the LICENSE file for details
