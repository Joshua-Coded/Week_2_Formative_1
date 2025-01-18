# Bus Route Navigation System

## Project Overview
A program implementing a bus route system using a doubly linked list. The system allows users to navigate through bus stops in both forward and backward directions, with a 3-second delay between stops.

## Project Structure
```
.
├── include/
│   └── bus_route.h        # Header file with structure and function declarations
├── src/
│   ├── bus_route/
│   │   ├── main.c        # Main program implementation
│   │   └── bus_route.c   # Bus route functions implementation
│   └── tests/
│       └── test_bus_route.c  # Test cases
├── data/
│   └── bus_route.txt     # Saved route data
└── Makefile
```

## Features
1. Navigate forward through bus stops
2. Navigate backward through bus stops
3. Add new bus stops
4. Modify existing bus stops
5. Display all stops
6. Persistent storage of bus routes

## Data Structure
```c
typedef struct BusStop {
    char name[MAX_STOP_NAME];
    struct BusStop* next;
    struct BusStop* prev;
} BusStop;
```

## Time Complexity Analysis

### 1. Adding a New Bus Stop
Time Complexity: O(n)
```c
void insertBusStop(BusStop** head, const char* name) {
    BusStop* newStop = createBusStop(name);  // O(1)
    
    if (*head == NULL) {                     // O(1)
        *head = newStop;
        return;
    }
    
    BusStop* current = *head;                // O(1)
    while (current->next != NULL) {          // O(n)
        current = current->next;
    }
    
    current->next = newStop;                 // O(1)
    newStop->prev = current;                 // O(1)
}
```

Steps Breakdown:
1. Node creation: O(1)
2. Empty list check: O(1)
3. Traversal to end: O(n)
4. Pointer updates: O(1)

Total = O(n) where n is number of existing stops

### 2. Other Operations
- Modify Bus Stop: O(n)
- Display Forward/Backward: O(n)
- Save/Load Route: O(n)

## Build and Run Instructions

### Compilation
```bash
make all              # Build everything
make bus_route        # Build only main program
make test_bus        # Build tests
```

### Run Program
```bash
./build/bus_route
```

### Run Tests
```bash
./build/test_bus
```

## Usage Example
```
Bus Route Navigation
====================
1. Travel Forward
2. Travel Backward
3. Add New Bus Stop
4. Modify Bus Stop
5. Display All Stops
6. Exit

Enter your choice: 1

Moving Forward through the Route:
===================================
Now at: Home
[3 seconds delay]
Now at: Market Square
[3 seconds delay]
Now at: Campus
```

## Memory Management
- Dynamic allocation for each bus stop
- Proper deallocation when program exits
- File handling for persistence

## Implementation Details

### Key Functions
1. `createBusStop`: Creates new bus stop node
2. `insertBusStop`: Adds stop at end of route
3. `modifyBusStop`: Changes existing stop name
4. `displayForward/Backward`: Shows route with delays
5. `saveRouteToFile/loadRouteFromFile`: Handles persistence

### Error Handling
- Memory allocation checks
- File operation validation
- Input validation
- Boundary checks

## File Format
bus_route.txt stores one stop per line:
```
Home
Market Square
Central Park
Library
Campus
```

## Testing
Test cases cover:
1. Basic operations
2. Edge cases
3. Memory management
4. File operations
