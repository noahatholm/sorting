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
    new_node->next = NULL;
    new_node->prev = NULL;

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
    if (!list){
        return;
    }

    printf("[");
    NodeT * current_node = list->head;
    while (current_node->next){
        printf("%d,", current_node->data->value);
        current_node=current_node->next;
    }
    printf("%d",current_node->data->value);
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

LinkedListT * linked_list_split(LinkedListT * list){
    if (!list || list->length == 1){
        return NULL;
    }

    //Find the midpoint
    NodeT * fast = list->head;
    NodeT * slow = list->head;

    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    //Found midpoint Now must split list
    LinkedListT * new_list = (LinkedListT  *)malloc(sizeof(LinkedListT));
    new_list->head = slow->next;
    //Update lengths
    new_list->length = list->length/2;
    list->length = list->length - list->length/2;

    //Update tails
    list->tail = slow;
    if (fast->next){fast=fast->next;}
    new_list->tail = fast;

    //Undo the links
    new_list->head->prev = NULL; 
    slow->next = NULL; 

    return new_list;
}

void linked_list_insert_after(LinkedListT * list,NodeT * node1, NodeT * node2){
    NodeT * temp = node1->next;

    node1->next = node2;
    node2->prev = node1;
    node2->next = temp;

    if (temp){
        temp->prev = node2;
    }
    list->length++;

    if (node1 == list->tail) {
        list->tail = node2;
    }
}



void linked_list_append_node(LinkedListT * list, NodeT * node){
    //Sanitise Node
    node->next = NULL;
    node->prev = NULL;

    if (!list->head){
        list->head = node;
    }

    if (list->tail){
        list->tail->next = node;
        node->prev = list->tail;

    }
    list->tail = node;

    list->length++;

}



