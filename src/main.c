#include <stdio.h>
#include <stdlib.h>

#include "analyse_sort.h"
#include "sort_bubble.h"
#include "linked_list.h"

#define START_N 500



ListsT * generate_lists(int size);
void print_lists(ListsT * test_lists);
void destroy_lists(ListsT * test_lists);

int main (){

    //Generate Lists
    ListsT * test_lists = generate_lists(START_N);

    //print_lists(test_lists);
    

    #ifdef BUBBLE
        analyse_sort(test_lists,START_N, bubble_sort);
    #elif defined(INSERTION)
        printf("Insert\n");
    #else
        printf("Everything\n");
    #endif

    //free test lists
    destroy_lists(test_lists);

    return 0;
}




ListsT * generate_lists(int size){
    //Allocate lists
    ListsT * test_lists = (ListsT *)malloc(sizeof(ListsT));
    test_lists->best_case_1 = linked_list_init();
    test_lists->best_case_2 = linked_list_init();
    test_lists->best_case_3 = linked_list_init();

    test_lists->average_case_1 = linked_list_init();
    test_lists->average_case_2 = linked_list_init();
    test_lists->average_case_3 = linked_list_init();

    test_lists->worst_case_1 = linked_list_init();
    test_lists->worst_case_2 = linked_list_init();
    test_lists->worst_case_3 = linked_list_init();



    //Best case lists already in order
    //Worst case reverse order
    //Averge Random Numbers
    for (int i = 0; i < size * 4; i++){
        int random_number = rand() % size; 

        if (i < size){
            NodeT * node1 = linked_list_append(test_lists->best_case_1,i);
            node1->data->orginal_order = i;

            NodeT * node4 = linked_list_append(test_lists->worst_case_1,size-i-1);
            node4->data->orginal_order = i;

            NodeT * node7 = linked_list_append(test_lists->average_case_1,random_number);
            node7->data->orginal_order = i;
        }
        if (i < size * 2){
            NodeT * node2 = linked_list_append(test_lists->best_case_2,i);
            node2->data->orginal_order = i;

            NodeT * node5 = linked_list_append(test_lists->worst_case_2,size*2-i-1);
            node5->data->orginal_order = i;

            NodeT * node8 = linked_list_append(test_lists->average_case_2,random_number);
            node8->data->orginal_order = i;
            
        }
        NodeT * node3 = linked_list_append(test_lists->best_case_3, i);
        node3->data->orginal_order = i;

        NodeT * node6 = linked_list_append(test_lists->worst_case_3, size*4-i-1);
        node6->data->orginal_order = i;

        NodeT * node9 = linked_list_append(test_lists->average_case_3,random_number);
        node9->data->orginal_order = i;
    }

    return test_lists;
}


void print_lists(ListsT * test_lists){
    print_linked_list(test_lists->best_case_1);
    print_linked_list(test_lists->best_case_2);
    print_linked_list(test_lists->best_case_3);
    print_linked_list(test_lists->worst_case_1);
    print_linked_list(test_lists->worst_case_2);
    print_linked_list(test_lists->worst_case_3);
    print_linked_list(test_lists->average_case_1);
    print_linked_list(test_lists->average_case_2);
    print_linked_list(test_lists->average_case_3); 
}


void destroy_lists(ListsT * test_lists){
    linked_list_destroy(test_lists->best_case_1);
    linked_list_destroy(test_lists->best_case_2);
    linked_list_destroy(test_lists->best_case_3);
    linked_list_destroy(test_lists->average_case_1);
    linked_list_destroy(test_lists->average_case_2);
    linked_list_destroy(test_lists->average_case_3);
    linked_list_destroy(test_lists->worst_case_1);
    linked_list_destroy(test_lists->worst_case_2);
    linked_list_destroy(test_lists->worst_case_3);

    free(test_lists);
}