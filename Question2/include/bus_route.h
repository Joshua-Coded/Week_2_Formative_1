#ifndef BUS_ROUTE_H
#define BUS_ROUTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for sleep function

#define MAX_STOP_NAME 50
#define ROUTE_FILE "data/bus_route.txt"

// Structure for bus stop node
typedef struct BusStop {
    char name[MAX_STOP_NAME];
    struct BusStop* next;
    struct BusStop* prev;
} BusStop;

// Function declarations
BusStop* createBusStop(const char* name);
void insertBusStop(BusStop** head, const char* name);
void displayForward(BusStop* head);
void displayBackward(BusStop* tail);
void freeBusRoute(BusStop* head);
BusStop* getTail(BusStop* head);
void saveRouteToFile(BusStop* head);
BusStop* loadRouteFromFile(void);

// New functions for modifying stops
int modifyBusStop(BusStop* head, int position, const char* newName);
BusStop* getBusStopAtPosition(BusStop* head, int position);
int getRouteLength(BusStop* head);
void displayAllStops(BusStop* head);

#endif // BUS_ROUTE_H
