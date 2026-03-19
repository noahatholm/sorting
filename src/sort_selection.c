#include "linked_list.h"
#include <stdio.h>

void selection_sort(LinkedListT * list){
    if (!list || list->length <= 1) return;
    for (int k = list->length -1; k > 0; k--) {
        NodeT *current = list->head;
        int pos = 0; 
        int max_value = current->data->value;
        NodeT *max_node = current;
        while (pos < k) {
            if  (current->data->value > max_value) {
                max_value = current->data->value;
                max_node = current;
            }
            // Move forward
            current = current->next;
            pos++;
        }
        if (max_value > current->data->value){
            linked_list_swap(current, max_node);
        }
    }
}