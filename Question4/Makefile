CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lm
SRC_DIR = src
BUILD_DIR = build

# Binary Search Tree source files
BST_SRC = $(SRC_DIR)/student_bst/student_bst.c $(SRC_DIR)/student_bst/main.c
BST_OBJ = $(BST_SRC:%.c=$(BUILD_DIR)/%.o)

all: directories bst_program

directories:
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)/student_bst

# Main program
bst_program: $(BST_OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/student_bst $^ $(LDFLAGS)

# Object file compilation
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: bst_program
	./$(BUILD_DIR)/student_bst

.PHONY: all directories clean run
