//
// Created by jerryzhou3 on 2/3/2021.
//

#include "QuickSort.h"

void QuickSort::quickSort(std::vector<int> &array) {
    int size = array.size();
    quickSort(array, 0, size - 1);
}

int QuickSort::partition(std::vector<int> &array, int left, int right) {
    int pivot_val = array[right];
    int pivot = left - 1;
    for (int i = left; i <= right - 1; i++) {
        if (array[i] <= pivot_val) {
            ++pivot;
            array[pivot] ^= array[i];
            array[i] ^= array[pivot];
            array[pivot] ^= array[i];
        }
    }
    array[pivot + 1] ^= array[right];
    array[right] ^= array[pivot + 1];
    array[pivot + 1] ^= array[right];
    return pivot + 1;
}

void QuickSort::quickSort(std::vector<int> &array, int left, int right) {
    if (left >= right) return;
    int pivot = partition(array, left, right);
    quickSort(array, left, pivot - 1);
    quickSort(array, pivot + 1, right);
}
