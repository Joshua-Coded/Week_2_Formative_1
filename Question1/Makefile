CC = gcc
CFLAGS = -Wall -I./include
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = $(SRC_DIR)/tests

# Question 1 - QuickSort
QUICKSORT_SRC = $(SRC_DIR)/quicksort/student.c $(SRC_DIR)/quicksort/main.c
QUICKSORT_OBJ = $(QUICKSORT_SRC:%.c=$(BUILD_DIR)/%.o)
QUICKSORT_TEST = $(TEST_DIR)/tests_quicksort.c

all: directories quicksort test_quicksort

directories:
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)/quicksort

quicksort: $(QUICKSORT_OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/quicksort $^

test_quicksort: $(BUILD_DIR)/$(SRC_DIR)/quicksort/student.o $(QUICKSORT_TEST)
	mkdir -p $(BUILD_DIR)/$(TEST_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_quicksort $^

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all directories cleani
