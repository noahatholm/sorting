#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"


LinkedListT * linked_list_init(void){
    LinkedListT * list = (LinkedListT * )malloc(sizeof(LinkedListT));
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

NodeT * node_init(int value){
    NodeT * new_node = (NodeT * )malloc(sizeof(NodeT));
    new_node->data = (DataT *)malloc(sizeof(DataT));
    new_node->data->value = value;

    return new_node;
}

NodeT * linked_list_append(LinkedListT * list, int value){
    NodeT * new_node = node_init(value);
    if (list->length == 0){
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
        new_node->prev = list->tail;

    }
    list->tail = new_node;
    list->length++;

    return new_node;
}

NodeT * linked_list_prepend(LinkedListT * list, int value){
    NodeT * new_node = node_init(value);

    if (list->length == 0){
        list->tail = new_node;
    }
    else{
        list->head->prev = new_node;
        new_node->next = list->head;
    }
    list->head = new_node;
    list->length++;

    return new_node;
}

int linked_list_pop(LinkedListT * list, int * value){
    if (list->length < 1){return -1;}
    if (value == NULL){return -2;}
    NodeT * tail = list->tail;
    *value = tail->data->value;
    if (list->length > 1){
        list->tail = list->tail->prev;
        tail->prev->next = NULL;
        
    }
    else{
        list->head = NULL;
        list->tail = NULL;
    }
    free_node(tail);
    list->length--;

    return 0;
}

int linked_list_empty(LinkedListT * list){
    return (list->length == 0);
}

int linked_list_length(LinkedListT * list){
    return list->length;
}

void linked_list_swap(NodeT * item1, NodeT * item2){
    DataT * temp = item1->data;
    item1->data = item2->data;
    item2->data = temp;
}

void linked_list_destroy(LinkedListT * list){
    NodeT * head = list->head;
    NodeT * next;
    while (head){
        next = head->next;
        free_node(head);
        head = next;
    }
    free(list);
}

void print_linked_list(LinkedListT * list){
    printf("[");
    NodeT * current_node = list->head;
    while (current_node){
        printf("%d,", current_node->data->value);
        current_node=current_node->next;
    }
    printf("]\n");

}



int free_node(NodeT * node){
    if (node){
        free(node->data);
        free(node);
        return 0;
    }
    return -1;
}




