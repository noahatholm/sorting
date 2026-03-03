#include <stdio.h>

#include "analyse_sort.h"
#include "sort_bubble.h"

int main (){

    //Generate Lists

    #ifdef BUBBLE
        analyse_sort(NULL, bubble_sort);
    #elif defined(INSERTION)
        printf("Insert\n");
    #else
        printf("Everything\n");
    #endif
    return 0;
}