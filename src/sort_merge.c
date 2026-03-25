#include "linked_list.h"

#include <stdio.h>

//Recombines the list in order
LinkedListT * merge(LinkedListT * list1, LinkedListT * list2){

    NodeT * l1_pointer = list1->head;
    NodeT * l2_pointer = list2->head;
    NodeT * temp;

    LinkedListT * new_list = linked_list_init();

    while (l1_pointer && l2_pointer){
        //Insert L1 into new list
        if (l1_pointer->data->value <= l2_pointer->data->value){
            temp = l1_pointer->next;
            linked_list_append_node(new_list,l1_pointer);
            l1_pointer = temp;
        }
        //Insert L2 into new list
        else{
            temp = l2_pointer->next;
            linked_list_append_node(new_list,l2_pointer);
            l2_pointer = temp;
        }
    }
    if (l1_pointer){
        while (l1_pointer){
            temp = l1_pointer->next;
            linked_list_append_node(new_list,l1_pointer);
            l1_pointer = temp;
        }
    }
    else if (l2_pointer){
        while(l2_pointer){
            temp = l2_pointer->next;
            linked_list_append_node(new_list,l2_pointer);
            l2_pointer = temp;
        }
    }

    return new_list;
}

//Recursively splits the list
void merge_sort(LinkedListT * list){
    if (list->length <= 1){
        return;
    }

    LinkedListT * list_2 = linked_list_split(list);
    merge_sort(list);
    merge_sort(list_2);
    list = merge(list,list_2);
    print_linked_list(list);

}




