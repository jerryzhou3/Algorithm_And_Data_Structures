//
// Created by jerryzhou3 on 2/2/2021.
//

#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include <iostream>
#include <limits.h>

class MinHeap {
    int* array;
    int capacity;
    int size;

public:
    MinHeap(int capacity);
    ~MinHeap();
    int getParent(int i);
    int getLeft(int i);
    int getRight(int i);
    int extractMin();
    void insert(int k);
    void MinHeapfy(int i);
};


#endif //DATASTRUCTURES_MINHEAP_H
