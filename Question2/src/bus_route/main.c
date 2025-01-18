#include "../../include/bus_route.h"

int main() {
    BusStop* head = loadRouteFromFile();
    
    if (head == NULL) {
        printf("Initializing with default bus stops...\n");
        insertBusStop(&head, "Home");
        insertBusStop(&head, "Market Square");
        insertBusStop(&head, "Central Park");
        insertBusStop(&head, "Library");
        insertBusStop(&head, "Campus");
        saveRouteToFile(head);
    }

    int choice;
    
    while (1) {
        printf("\nBus Route Navigation\n");
        printf("====================\n");
        printf("1. Travel Forward\n");
        printf("2. Travel Backward\n");
        printf("3. Add New Bus Stop\n");
        printf("4. Modify Bus Stop\n");
        printf("5. Display All Stops\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // Clear newline

        switch (choice) {
            case 1: // Travel Forward
                if (head == NULL) {
                    printf("No bus stops in the route!\n");
                } else {
                    displayForward(head);
                }
                break;

            case 2: // Travel Backward
                if (head == NULL) {
                    printf("No bus stops in the route!\n");
                } else {
                    displayBackward(getTail(head));
                }
                break;

            case 3: { // Add New Stop
                char newStop[MAX_STOP_NAME];
                printf("Enter new bus stop name: ");
                if (fgets(newStop, MAX_STOP_NAME, stdin) != NULL) {
                    newStop[strcspn(newStop, "\n")] = 0;
                    if (strlen(newStop) > 0) {
                        insertBusStop(&head, newStop);
                        saveRouteToFile(head);
                        printf("Bus stop '%s' added successfully!\n", newStop);
                    } else {
                        printf("Error: Stop name cannot be empty!\n");
                    }
                }
                break;
            }

            case 4: { // Modify Bus Stop
                if (head == NULL) {
                    printf("No bus stops to modify!\n");
                    break;
                }

                displayAllStops(head);
                int position;
                printf("\nEnter the number of the stop to modify: ");
                scanf("%d", &position);
                getchar(); // Clear newline

                if (position < 1 || position > getRouteLength(head)) {
                    printf("Invalid position!\n");
                    break;
                }

                char newName[MAX_STOP_NAME];
                printf("Enter new name for the stop: ");
                if (fgets(newName, MAX_STOP_NAME, stdin) != NULL) {
                    newName[strcspn(newName, "\n")] = 0;
                    if (strlen(newName) > 0) {
                        if (modifyBusStop(head, position, newName)) {
                            saveRouteToFile(head);
                            printf("Bus stop modified successfully!\n");
                        }
                    } else {
                        printf("Error: Stop name cannot be empty!\n");
                    }
                }
                break;
            }

            case 5: // Display All Stops
                displayAllStops(head);
                break;

            case 6: // Exit
                saveRouteToFile(head);
                freeBusRoute(head);
                printf("Thank you for using the Bus Route Navigation!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
