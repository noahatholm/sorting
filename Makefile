CC = gcc
CFLAGS = -ggdb -Werror -Iinclude
OUT_DIR = out
SRC_DIR = src
TEST_DIR = tests
TARGET = $(OUT_DIR)/sort
DEFAULT_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/analyse_sort.c $(SRC_DIR)/linked_list.c
RUN_FLAGS = taskset -c 1 #Restricts to only one core should lead to more consistant results by reducing cache misses hopefully

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

list.tests : $(OUT_DIR)
	$(CC) $(CFLAGS) $(TEST_DIR)/linked_list_tests.c $(SRC_DIR)/linked_list.c -o $(OUT_DIR)/linked_list_test
	./$(OUT_DIR)/linked_list_test



#Diff compiler tags compile each sort
bubble: $(OUT_DIR)
	$(CC) $(CFLAGS) -DBUBBLE $(DEFAULT_FILES) $(SRC_DIR)/sort_bubble.c -o $(OUT_DIR)/sort_bubble
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_bubble

insertion: $(OUT_DIR)
	$(CC) $(CFLAGS) -DINSERTION $(DEFAULT_FILES) $(SRC_DIR)/sort_insertion.c  -o $(OUT_DIR)/sort_insertion
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_insertion

sorting: $(OUT_DIR)
	$(CC) $(CFLAGS) $(DEFAULT_FILES) $(SRC_DIR)/sort_* -o $(OUT_DIR)/sort_compare
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_compare

clean:
	rm -rf $(OUT_DIR)