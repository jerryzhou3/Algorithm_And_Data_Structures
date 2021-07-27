//
// Created by jerryzhou3 on 2/2/2021.
//

#include "MinHeap.h"

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->array = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] this->array;
}

int MinHeap::getParent(int i) {
    return (i - 1) / 2;
}

int MinHeap::getLeft(int i) {
    return i * 2 + 1;
}

int MinHeap::getRight(int i) {
    return i * 2 + 2;
}

int MinHeap::extractMin() {
    if (this->size <= 0) return INT_MAX;
    if (this->size == 1) {
        --this->size;
        return this->array[0];
    }
    int res = this->array[0];
    this->array[0] = this->array[this->size-1];
    --this->size;
    MinHeapfy(0);
    return res;
}

void MinHeap::MinHeapfy(int i) {
    int left = getLeft(i);
    int right = getRight(i);
    int smallest = i;
    if (left < this->size && this->array[left] < this->array[smallest]) smallest = left;
    if (right < this->size && this->array[right] < this->array[smallest]) smallest = right;
    if (smallest != i) {
        int temp = this->array[smallest];
        this->array[smallest] = this->array[i];
        this->array[i] = temp;
        MinHeapfy(smallest);
    }
}

void MinHeap::insert(int k) {
    if (this->size >= this->capacity) {
        std::cout << "Heap full, cannot insert!" << std::endl;
        return;
    }
    ++this->size;
    int idx = this->size - 1;
    this->array[idx] = k;

    while (idx > 0 && this->array[getParent(idx)] > k) {
        this->array[idx] = this->array[getParent(idx)];
        this->array[getParent(idx)] = k;
        idx = getParent(idx);
    }
}


