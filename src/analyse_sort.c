#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#include "analyse_sort.h"


void analyse_sort(ListsT * test_lists, SortStrategy strategy){
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

    print_results(results);

    free(time_results);
    //free(results);
}


int time_sort(LinkedListT * list, SortStrategy sort){
    struct timeval start_time;
    struct timeval end_time;
    

    gettimeofday(&start_time,NULL);
    sort(list);
    gettimeofday(&end_time,NULL);
    return end_time.tv_usec - start_time.tv_usec;
}

enum TimeComplexity estimate_complexity(int run1, int run2, int run3){ //assumes same difference between runs



}

TestResultsT * check_results(ListsT * test_lists, TimeResultsT * time_results){
    TestResultsT * results  = (TestResultsT *)malloc(sizeof(TestResultsT));

    //Estimate complexity
    // results->best_case = estimate_complexity(time_results->best_time_1, time_results->best_time_2, time_results->best_time_3);
    // results->average_case = estimate_complexity(time_results->average_time_1, time_results->average_time_2,time_results->average_time_3);
    // results->worst_case = estimate_complexity(time_results->worst_time_1, time_results->worst_time_2, time_results->worst_time_3);

    printf("")

    //Check Correctness

    //Check stability

    //Check 

    return results;
}

void print_results(TestResultsT * results){
    printf("temp\n");
}