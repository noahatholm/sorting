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
  CONSTANT,
  LOGARITHMIC,
  LINEAR,
  LOGLINEAR,
  QUADRATIC,
  EXPONENTIAL,
  FACTORIAL,
  UNKNOWN
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

void analyse_sort(ListsT * test_lists, int start_n, SortStrategy strategy); //Apparantly this is c method to do strategy pattern 

long long time_sort(LinkedListT * list, SortStrategy sort);

TestResultsT * check_results(ListsT * test_lists, TimeResultsT * time_results);

void print_results(TestResultsT * results, TimeResultsT * time_results, int start_n);

enum TimeComplexity estimate_complexity(double n1, double n2, double n3);

int check_correctness(LinkedListT * list);

int check_stability(LinkedListT * list);