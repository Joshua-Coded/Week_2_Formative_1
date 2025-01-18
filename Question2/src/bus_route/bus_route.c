#include "../../include/bus_route.h"

// Create a new bus stop node
BusStop* createBusStop(const char* name) {
    BusStop* newStop = (BusStop*)malloc(sizeof(BusStop));
    if (newStop == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    strncpy(newStop->name, name, MAX_STOP_NAME - 1);
    newStop->name[MAX_STOP_NAME - 1] = '\0';
    newStop->next = NULL;
    newStop->prev = NULL;
    return newStop;
}

// Insert a bus stop at the end of the route
void insertBusStop(BusStop** head, const char* name) {
    BusStop* newStop = createBusStop(name);
    
    // If list is empty
    if (*head == NULL) {
        *head = newStop;
        return;
    }
    
    // Find the last stop
    BusStop* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Link the new stop
    current->next = newStop;
    newStop->prev = current;
}

// Modify a bus stop at a specific position (1-based indexing)
int modifyBusStop(BusStop* head, int position, const char* newName) {
    if (position < 1) {
        printf("Invalid position! Position must be positive.\n");
        return 0;
    }

    BusStop* current = head;
    int currentPos = 1;

    // Find the bus stop at the specified position
    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }

    if (current == NULL) {
        printf("Position %d not found in route!\n", position);
        return 0;
    }

    // Update the name
    strncpy(current->name, newName, MAX_STOP_NAME - 1);
    current->name[MAX_STOP_NAME - 1] = '\0';
    return 1;
}

// Get number of stops in route
int getRouteLength(BusStop* head) {
    int length = 0;
    BusStop* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Display all stops with numbers
void displayAllStops(BusStop* head) {
    if (head == NULL) {
        printf("No stops in the route!\n");
        return;
    }

    printf("\nCurrent Bus Stops:\n");
    printf("=================\n");
    BusStop* current = head;
    int position = 1;

    while (current != NULL) {
        printf("%d. %s\n", position++, current->name);
        current = current->next;
    }
}

// Display route forward with 3-second delay
void displayForward(BusStop* head) {
    BusStop* current = head;
    printf("\nMoving Forward through the Route:\n");
    printf("===================================\n");
    
    while (current != NULL) {
        printf("Now at: %s\n", current->name);
        sleep(3);  // 3-second delay
        current = current->next;
    }
    printf("\nReached the last stop!\n");
}

// Display route backward with 3-second delay
void displayBackward(BusStop* tail) {
    BusStop* current = tail;
    printf("\nMoving Backward through the Route:\n");
    printf("===================================\n");
    
    while (current != NULL) {
        printf("Now at: %s\n", current->name);
        sleep(3);  // 3-second delay
        current = current->prev;
    }
    printf("\nReached the first stop!\n");
}

// Get the last stop in the route
BusStop* getTail(BusStop* head) {
    if (head == NULL) return NULL;
    
    BusStop* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

// Free memory used by the bus route
void freeBusRoute(BusStop* head) {
    BusStop* current = head;
    while (current != NULL) {
        BusStop* temp = current;
        current = current->next;
        free(temp);
    }
}

// Save route to file
void saveRouteToFile(BusStop* head) {
    FILE* file = fopen(ROUTE_FILE, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    BusStop* current = head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->name);
        current = current->next;
    }

    fclose(file);
    printf("Route saved successfully!\n");
}

// Load route from file
BusStop* loadRouteFromFile(void) {
    FILE* file = fopen(ROUTE_FILE, "r");
    if (file == NULL) {
        printf("No saved route found. Starting with empty route.\n");
        return NULL;
    }

    BusStop* head = NULL;
    char name[MAX_STOP_NAME];

    while (fgets(name, MAX_STOP_NAME, file)) {
        // Remove newline character if present
        name[strcspn(name, "\n")] = 0;
        insertBusStop(&head, name);
    }

    fclose(file);
    printf("Route loaded successfully!\n");
    return head;
}
