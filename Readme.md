# Data Structures and Algorithms Implementation

![Project Overview](images/algorithm-analysis.svg)

A comprehensive implementation of fundamental data structures and algorithms in C, focusing on sorting, linked lists, and tree structures.

## Questions Overview

### Question 1: QuickSort Implementation
- Sorts student records by grades
- Time Complexity: O(n log n) average case
- File-based I/O operations
- Complete sorting solution with analysis

### Question 2: Bus Route System
- Doubly linked list implementation
- Interactive navigation system
- 3-second delay between stops
- Bidirectional traversal

### Question 3: Binary Tree Operations
- Complete binary tree implementation
- Multiple tree operations:
  * Root node access
  * Leaf node identification
  * Sibling relationships
  * Parent-child relationships
  * Grandchildren access

### Question 4: Binary Search Tree
- Efficient student record searching
- Last name-based indexing
- Comparative analysis with linear search
- Advanced tree operations

## Directory Structure
```
Week_2_Formative_1/
├── Question1/            # QuickSort Implementation
│   ├── data/
│   │   └── students.txt
│   ├── include/
│   ├── src/
│   ├── Makefile
│   └── README.md
├── Question2/            # Bus Route Implementation
├── Question3/            # Binary Tree Implementation
└── Question4/            # BST Implementation
```

## Build Instructions

Each question has its own build process:

```bash
# For each question (1-4):
cd Question[N]
make clean
make all
```

## Time Complexity Analysis

### 1. QuickSort (Question 1)
```
Average Case: O(n log n)
- Balanced partitioning
- Efficient for large datasets
- Optimal comparison-based sorting

Worst Case: O(n²)
- Rare with good pivot selection
- Not typical in practice
```

### 2. Bus Route (Question 2)
```
Adding New Stop: O(n)
- Must traverse to end
- Linear time operation
- Cannot be optimized without structural changes
```

### 3. Binary Tree (Question 3)
```
Node Operations: O(1)
- Direct access to relationships
- Constant time for most operations

Tree Traversal: O(n)
- Must visit all nodes
- Complete coverage required
```

### 4. BST (Question 4)
```
Search Operations: O(log n)
- Efficient for large datasets
- Balanced tree assumption
- Significant improvement over linear search
```

## Testing

Each implementation includes comprehensive tests:
- Functionality verification
- Edge case handling
- Performance validation
- Memory management

## Features Highlight

1. **Modular Design**
   - Separate compilation units
   - Clear interfaces
   - Reusable components

2. **Error Handling**
   - Input validation
   - Memory management
   - File operation safety

3. **Documentation**
   - Detailed READMEs
   - Code comments
   - Usage examples

4. **Performance**
   - Optimized implementations
   - Efficient algorithms
   - Scalable solutions

## Author
Joshua Alana
