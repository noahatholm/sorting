#include <stdio.h>

#include "sort_bubble.h"
#include "linked_list.h"


void bubble_sort(LinkedListT * list) {
    if (!list || list->length <= 1) return;

    for (int k = list->length - 1; k > 0; k--) {
        NodeT *last = list->head;
        NodeT *current = last->next;
        int pos = 1; 

        while (current && pos <= k) {
            if (current->data->value < last->data->value) {
                linked_list_swap(current, last);
            }
            // Move forward
            last = current;
            current = current->next;
            pos++;
        }
    }
}


void bubble_sort_adpative(LinkedListT * list){
    if (!list || list->length <= 1) return;
    int swap_made = 0;
    for (int k = list->length - 1; k > 0; k--) {
        swap_made = 0;
        NodeT *last = list->head;
        NodeT *current = last->next;
        int pos = 1; 

        while (current && pos <= k) {
            if (current->data->value < last->data->value) {
                linked_list_swap(current, last);
                swap_made = 1;
            }
            // Move forward
            last = current;
            current = current->next;
            pos++;
        }
        if (!swap_made)return; //If a full pass is made without any swaps necessary than it must be in order already
    } 
}