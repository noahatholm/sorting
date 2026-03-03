#include "analyse_sort.h"


void analyse_sort(LinkedListT * list, SortStrategy strategy){
    if (strategy){
        strategy(list);
    }
}