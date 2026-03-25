CC = gcc
CFLAGS = -ggdb -Werror -Iinclude
OUT_DIR = out
SRC_DIR = src
TEST_DIR = tests
TARGET = $(OUT_DIR)/sort
DEFAULT_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/analyse_sort.c $(SRC_DIR)/linked_list.c
RUN_FLAGS = taskset -c 1 #Restricts to only one core should lead to more consistant results by reducing cache misses hopefully
DEFAULT_N = 4

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

list.tests : $(OUT_DIR)
	$(CC) $(CFLAGS) $(TEST_DIR)/linked_list_tests.c $(SRC_DIR)/linked_list.c -o $(OUT_DIR)/linked_list_test
	./$(OUT_DIR)/linked_list_test



#Diff compiler tags compile each sort
bubble: $(OUT_DIR)
	$(CC) $(CFLAGS) -DBUBBLE $(DEFAULT_FILES) $(SRC_DIR)/sort_bubble.c -o $(OUT_DIR)/sort_bubble
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_bubble $(DEFAULT_N)

bubble_adaptive: $(OUT_DIR)
	$(CC) $(CFLAGS) -DBUBBLE_ADAPTIVE $(DEFAULT_FILES) $(SRC_DIR)/sort_bubble.c -o $(OUT_DIR)/sort_bubble_adaptive
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_bubble_adaptive $(DEFAULT_N)

insertion: $(OUT_DIR)
	$(CC) $(CFLAGS) -DINSERTION $(DEFAULT_FILES) $(SRC_DIR)/sort_insertion.c  -o $(OUT_DIR)/sort_insertion
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_insertion $(DEFAULT_N)

selection: $(OUT_DIR)
	$(CC) $(CFLAGS) -DSELECTION $(DEFAULT_FILES) $(SRC_DIR)/sort_selection.c -o $(OUT_DIR)/sort_selection
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_selection $(DEFAULT_N)

merge: $(OUT_DIR)
	$(CC) $(CFLAGS) -DMERGE $(DEFAULT_FILES) $(SRC_DIR)/sort_merge.c -o $(OUT_DIR)/sort_merge
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_merge $(DEFAULT_N)

sorting: $(OUT_DIR)
	$(CC) $(CFLAGS) $(DEFAULT_FILES) $(SRC_DIR)/sort_* -o $(OUT_DIR)/sort_compare
	$(RUN_FLAGS) ./$(OUT_DIR)/sort_compare $(DEFAULT_N)

clean:
	rm -rf $(OUT_DIR)