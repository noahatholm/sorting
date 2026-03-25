#pragma once

#include "linked_list.h"

void merge_sort(LinkedListT * list);

LinkedListT * merge(LinkedListT * list1, LinkedListT * list2);

void merge_sort_adaptive(LinkedListT * list);