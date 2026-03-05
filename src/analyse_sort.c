#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "analyse_sort.h"

void analyse_sort(ListsT * test_lists, int start_n, SortStrategy strategy){
    if (!strategy){
        return;
    }

    TimeResultsT * time_results = (TimeResultsT *)malloc(sizeof(TimeResultsT));
    //Time the best cases
    time_results->best_time_1 = time_sort(test_lists->best_case_1,strategy);
    time_results->best_time_2 = time_sort(test_lists->best_case_2,strategy);
    time_results->best_time_3 = time_sort(test_lists->best_case_3,strategy);

    //Time the average cases
    time_results->average_time_1 = time_sort(test_lists->average_case_1,strategy);
    time_results->average_time_2 = time_sort(test_lists->average_case_2,strategy);

    time_results->average_time_3 = time_sort(test_lists->average_case_3,strategy);

    //Time the worst cases
    time_results->worst_time_1 = time_sort(test_lists->worst_case_1,strategy);

    time_results->worst_time_2 = time_sort(test_lists->worst_case_2,strategy);
    time_results->worst_time_3 = time_sort(test_lists->worst_case_3,strategy);


    
    TestResultsT * results = check_results(test_lists, time_results);


    print_results(results,time_results,start_n);

    free(time_results);
    free(results);
}


long long time_sort(LinkedListT * list, SortStrategy sort) {
    struct timespec start, end;

    // Use MONOTONIC to avoid system clock adjustments
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    sort(list);
    
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Convert everything to nanoseconds so you don't lose the difference
    long long start_ns = (long long)start.tv_sec * 1000000000LL + start.tv_nsec;
    long long end_ns = (long long)end.tv_sec * 1000000000LL + end.tv_nsec;

    return end_ns - start_ns;
}

char * timeComplexity_To_String(enum TimeComplexity t){
    switch (t){
        case CONSTANT:
            return "O(1)";
        case LOGARITHMIC:
            return "O(LogN)";
        case LINEAR:
            return "O(N)";
        case LOGLINEAR:
            return "O(NLogN)";
        case QUADRATIC:
            return "O(N^2)";
        case EXPONENTIAL:
            return "O(2^N)";
        case FACTORIAL:
            return "O(N!)";
        default:
            return "O(?)";
    }
}

char * bool_to_string(int b){
    if (b) return "True";
    return "False";
}

enum TimeComplexity estimate_complexity(double n1, double n2, double n3){ //assumes start doubles between runs
    //Calculate differentials
    double order1_1 = n2/n1;
    double order1_2 = n3/n2;

    double order2_1 = order1_2 / order1_1;
    printf("First Order: %lf Second Order %lf\n", order1_2, order2_1);

    //Still tweaking these numbers
    if (order1_2 < 1.2) return CONSTANT;
    if (order1_2 < 2.1 && order2_1) return LINEAR;
    if (order1_2 > 3.7 && order1_2 < 4.3 && order2_1 >= 0.99) return QUADRATIC;
    if (order1_2 > 2.1 && order1_2 < 3.0 && order2_1 < 0.99) return LOGLINEAR;
    if (order1_2 > 5) return EXPONENTIAL;
    if (order1_1 > 20 && order2_1 > 2) return FACTORIAL;

    return UNKNOWN;

}

TestResultsT * check_results(ListsT * test_lists, TimeResultsT * time_results){
    TestResultsT * results  = (TestResultsT *)malloc(sizeof(TestResultsT));

    //Estimate complexity
    results->best_case = estimate_complexity(time_results->best_time_1, time_results->best_time_2, time_results->best_time_3);
    results->average_case = estimate_complexity(time_results->average_time_1, time_results->average_time_2,time_results->average_time_3);
    results->worst_case = estimate_complexity(time_results->worst_time_1, time_results->worst_time_2, time_results->worst_time_3);



    //Check Correctness
    results->correctness = (check_correctness(test_lists->average_case_3) && check_correctness(test_lists->worst_case_3));


    //Check stability
    results->stability = (check_stability(test_lists->average_case_3) && results->correctness); //stability check only works if list is sorted


    //Check adaptability
    results->adaptability = results->best_case < results->worst_case; //Relies on the fact that enums are ints and they are in increasing order
    return results;
}

int check_stability(LinkedListT * list){ //Must be in order for this to work
    int last_value = -1;
    int last_order = -1;
    NodeT * current = list->head;
    while (current){
        if (current->data->value == last_value && current->data->orginal_order < last_order) return 0;
        last_value = current->data->value;
        last_order = current->data->orginal_order;
        current = current->next;
    }
    return 1;
}

int check_correctness(LinkedListT * list){
    int last_value = -1;
    NodeT * current = list->head;
    while (current){
        if (last_value > current->data->value){
            return 0;
        }
        last_value = current->data->value;
        current = current->next;
    }
    return 1;
}

void print_results(TestResultsT * results, TimeResultsT * time_results, int start_n){
    printf("---------------Timer---------------\nN:        %5d     %5d     %5d\n", start_n, start_n * 2, start_n * 4);
    printf("Best:   %7d   %7d   %7d\n",time_results->best_time_1, time_results->best_time_1,time_results->best_time_3);
    printf("Average:%7d   %7d   %7d\n",time_results->average_time_1, time_results->average_time_2,time_results->average_time_3);
    printf("Worst:  %7d   %7d   %7d\n",time_results->worst_time_1, time_results->worst_time_2,time_results->worst_time_3);


    printf("-----------Time Complexity---------\nBest Case: %s\nAverage Case: %s\nWorst Case: %s\n", timeComplexity_To_String(results->best_case), timeComplexity_To_String(results->average_case), timeComplexity_To_String(results->worst_case));

    printf("--------------Properties-----------\nCorrectness: %s\nStability: %s\nAdaptability: %s\n",bool_to_string(results->correctness), bool_to_string(results->stability), bool_to_string(results->adaptability));
    
}