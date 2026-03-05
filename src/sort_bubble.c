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