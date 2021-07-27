//
// Created by jerryzhou3 on 2/3/2021.
//

#ifndef DATASTRUCTURES_QUICKSORT_H
#define DATASTRUCTURES_QUICKSORT_H
#include<vector>

class QuickSort {
    static int partition(std::vector<int>& array, int left, int right);
    static void quickSort(std::vector<int>& array, int left, int right);
public:
    static void quickSort(std::vector<int>& array);
};


#endif //DATASTRUCTURES_QUICKSORT_H
