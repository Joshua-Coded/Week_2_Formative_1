#include "../../include/bus_route.h"
#include <assert.h>

void test_bus_route() {
    // Test 1: Initialize empty route
    BusStop* head = NULL;
    assert(head == NULL);

    // Test 2: Add first stop
    insertBusStop(&head, "Stop 1");
    assert(head != NULL);
    assert(head->prev == NULL);
    assert(head->next == NULL);
    assert(strcmp(head->name, "Stop 1") == 0);

    // Test 3: Add second stop
    insertBusStop(&head, "Stop 2");
    assert(head->next != NULL);
    assert(head->next->prev == head);
    assert(strcmp(head->next->name, "Stop 2") == 0);

    // Test 4: Verify tail connections
    BusStop* tail = getTail(head);
    assert(tail != NULL);
    assert(tail->next == NULL);
    assert(tail->prev->next == tail);

    // Test 5: Memory management
    freeBusRoute(head);
    printf("All tests passed!\n");
}

int main() {
    printf("Running bus route tests...\n");
    test_bus_route();
    return 0;
}
