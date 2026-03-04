#pragma once


typedef struct Data{
    int value;
    int orginal_order; //Used to check stability 
} DataT;

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    struct Data* data;
} NodeT;


typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
    unsigned int length;
} LinkedListT;


LinkedListT * linked_list_init(void);

NodeT * node_init(int value);

NodeT * linked_list_append(LinkedListT * list, int value);

NodeT * linked_list_prepend(LinkedListT * list, int value);

//Pops from back
int linked_list_pop(LinkedListT * list, int * value);

int linked_list_empty(LinkedListT * list);

int linked_list_length(LinkedListT * list);

void linked_list_swap(NodeT * item1, NodeT * item2);

void linked_list_destroy(LinkedListT * list);

int free_node(NodeT * node);

void print_linked_list(LinkedListT * list);



