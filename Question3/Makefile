CC = gcc
CFLAGS = -Wall -I./include
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = $(SRC_DIR)/tests

# Binary Tree source files
BT_SRC = $(SRC_DIR)/binary_tree/binary_tree.c $(SRC_DIR)/binary_tree/main.c
BT_OBJ = $(BT_SRC:%.c=$(BUILD_DIR)/%.o)
BT_TEST = $(TEST_DIR)/test_binary_tree.c

all: directories binary_tree test_binary

directories:
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)/binary_tree
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)

# Main program
binary_tree: $(BT_OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/binary_tree $^

# Test program
test_binary: $(BUILD_DIR)/$(SRC_DIR)/binary_tree/binary_tree.o $(BT_TEST)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_binary $^

# Object file compilation
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: binary_tree
	./$(BUILD_DIR)/binary_tree

# Run tests
test: test_binary
	./$(BUILD_DIR)/test_binary

.PHONY: all directories clean run test
