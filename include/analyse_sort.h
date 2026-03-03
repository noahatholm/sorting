#pragma once
#include "linked_list.h"


typedef void (*SortStrategy)(LinkedListT * list);

void analyse_sort(LinkedListT * list, SortStrategy strategy); //Apparantly this is c method to do strategy pattern 