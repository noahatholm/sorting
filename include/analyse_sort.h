#pragma once
#include "linked_list.h"

typedef struct Lists{
    struct LinkedList * best_case_1;
    struct LinkedList * best_case_2;
    struct LinkedList * best_case_3;
    struct LinkedList * average_case_1;
    struct LinkedList * average_case_2;
    struct LinkedList * average_case_3;
    struct LinkedList * worst_case_1;
    struct LinkedList * worst_case_2;
    struct LinkedList * worst_case_3;
} ListsT;

enum TimeComplexity {
  ONE,
  LogN,
  N,
  NLogN,
  N,
  NQuad,
  NExp,
  NFact
}; 

typedef struct TimeResults{
    int best_time_1;
    int best_time_2;
    int best_time_3;
    int average_time_1;
    int average_time_2;
    int average_time_3;
    int worst_time_1;
    int worst_time_2;
    int worst_time_3;
} TimeResultsT;

typedef struct TestResults{
    int correctness;
    int stability;
    int adaptability;
    enum TimeComplexity best_case;
    enum TimeComplexity average_case;
    enum TimeComplexity worst_case;
} TestResultsT;

typedef void (*SortStrategy)(LinkedListT * list);

void analyse_sort(ListsT * test_lists, SortStrategy strategy); //Apparantly this is c method to do strategy pattern 

int time_sort(LinkedListT * list, SortStrategy sort);

TestResultsT * check_results(ListsT * test_lists, TimeResultsT * time_results);

void print_results(TestResultsT * results);

enum TimeComplexity estimate_complexity(int run1, int run2, int run3);