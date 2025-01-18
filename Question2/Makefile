CC = gcc
CFLAGS = -Wall -I./include
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = $(SRC_DIR)/tests

# Bus Route source files
BUS_SRC = $(SRC_DIR)/bus_route/bus_route.c $(SRC_DIR)/bus_route/main.c
BUS_OBJ = $(BUS_SRC:%.c=$(BUILD_DIR)/%.o)
BUS_TEST = $(TEST_DIR)/test_bus_route.c

all: directories bus_route test_bus

directories:
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)/bus_route
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)

# Main program
bus_route: $(BUS_OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/bus_route $^

# Test program
test_bus: $(BUILD_DIR)/$(SRC_DIR)/bus_route/bus_route.o $(BUS_TEST)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_bus $^

# Object file compilation
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: bus_route
	./$(BUILD_DIR)/bus_route

# Run tests
test: test_bus
	./$(BUILD_DIR)/test_bus

.PHONY: all directories clean run test
