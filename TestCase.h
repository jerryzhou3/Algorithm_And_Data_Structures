//
// Created by jerryzhou3 on 1/4/2021.
//

#ifndef DATASTRUCTURES_TESTCASE_H
#define DATASTRUCTURES_TESTCASE_H

#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "MinHeap.h"
#include "QuickSort.h"

class TestCase {
    static void doTestBinarySearchTree();
    static void doTestAVLTree();
    static void doTestMinHeap();
    static void doTestQuickSort();
public:
    static void testBinarySearchTree();
    static void testAVLTree();
    static void testMinHeap();
    static void testQuickSort();
};


#endif //DATASTRUCTURES_TESTCASE_H
