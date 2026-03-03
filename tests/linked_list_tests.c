#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

void create_destroy(){
    LinkedListT * test_list = linked_list_init(); 
    assert(test_list);

    assert(test_list->length == 0);
    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(linked_list_empty(test_list));
    linked_list_destroy(test_list);
}

void create_add_destroy(){
    LinkedListT * test_list = linked_list_init(); 
    assert(test_list);

    linked_list_append(test_list,6);
    linked_list_append(test_list,7);

    //print_linked_list(test_list);
    assert(test_list->length == 2);
    assert(!linked_list_empty(test_list));

    int value;

    linked_list_pop(test_list, &value);
    assert(value == 7);
    assert(test_list->length == 1);

    linked_list_destroy(test_list);
}

void test_swap(){
    LinkedListT * test_list = linked_list_init(); 
    assert(test_list);

    
    NodeT * pos0 = linked_list_append(test_list,6);
    NodeT * pos1 = linked_list_append(test_list,7);
    NodeT * pos2 = linked_list_prepend(test_list,8);

    assert(test_list->length == 3);


    linked_list_swap(pos0,pos1);
    linked_list_swap(pos1, pos2);

    assert(test_list->length == 3);
    //print_linked_list(test_list);

    int value;
    for (int i = 8; i >= 6 ; i--){
        linked_list_pop(test_list,&value);
        //print_linked_list(test_list);
        assert(value == i);
    }

    assert(linked_list_empty(test_list));
    linked_list_destroy(test_list);
}

int main(){
    create_destroy();
    create_add_destroy();
    test_swap();
    printf("Linked List Tests Executed Successfully\n");
    return 0;
}

