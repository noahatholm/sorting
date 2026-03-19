# Sorting
Got bored in Algorithms and Data Structures lab and didn't wanna write java <br>
Implemented a few sorting algortithm and some basic testing

Can run each algorithm using make e.g <br>
`make bubble` <br>
Outputs: 
```
--------------------Timer-------------------
N:           10000        20000        40000
Best:    179397422    796670647   3829285626
Average: 221297947    904730679   4555638310
Worst:   136839360    650106721   3103174482
----------------Time Complexity-------------
Best Case: O(N^2)
Average Case: O(N^2)
Worst Case: O(N^2)
-------------------Properties---------------
Correctness: True
Stability: True
Adaptability: False
```


## Test Results 
I wrote a basic test suite that attempts to analyse time complexity only going of the ms values of 3 runs <br>
I might move to a counting mechanism rather than timer for more accurate estimations in the future <br>
It works decently well but can be inconsistent at small enough N's and struggles with the avergage case for adaptable algorithms but that is expected. <br>
Each algorithm has an initial N then the subsequent N values are 2N, and 4N
Below is the analysis of each sort from `analyse_sort.c`

| Sort Name            | Initial N | T(Best Case) | T(Average Case) | T(Worst Case) | O(Best Case) | O(Average Case) | O(Worst Case) | Correct? | Stable? | Adaptable? | Notes |
|----------------------|-----------|--------------|-----------------|---------------|--------------|----------------|---------------|----------|---------|------------|---------|
| Bubble Sort          |10000|3841418878 |4798389763|3232710944|O(N^2)|O(N^2)|O(N^2)|✅|✅|❌| |
| Adaptive Bubble Sort |     10000     |674042|6222117235|3165554911|O(N)|O(?)|O(N^2)|✅|✅|✅| |
| Selection Sort |     10000     |3726912274|1985052045|2365919588|O(N^2)|O(N^2)|O(N^2)|✅|❌|❌| |
|                      |           |              |                 |               |              |                |               |          |         |            |