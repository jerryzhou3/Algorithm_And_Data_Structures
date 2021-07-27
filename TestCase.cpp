//
// Created by jerryzhou3 on 1/4/2021.
//

#include "TestCase.h"

void TestCase::doTestBinarySearchTree() {
    auto* BST = new BinarySearchTree();
    std::cout << "insert 5" << std::endl;
    BST->insert(5);
    std::cout << "insert 3" << std::endl;
    BST->insert(3);
    std::cout << "insert 10" << std::endl;
    BST->insert(10);
    std::cout << "insert 7" << std::endl;
    BST->insert(7);
    std::cout << "insert 4" << std::endl;
    BST->insert(4);
    std::cout << std::endl;

    std::cout << "height: " << BST->getHeight() << std::endl;
    std::cout << "max: " << BST->getMax() << std::endl;
    std::cout << "min: " << BST->getMin() << std::endl;
    std::cout << "contains 7: " << std::boolalpha << BST->contains(7) << std::endl;
    std::cout << "contains 6: " << std::boolalpha << BST->contains(6) << std::endl;
    std::cout << "is full: " << std::boolalpha << BST->isFull() << std::endl;
    std::cout << "is balanced: " << std::boolalpha << BST->isBalanced() << std::endl;
    BST->printTree();
    std::cout << std::endl;

    std::cout << "remove 3" << std::endl;
    BST->remove(3);
    BST->printTree();
    std::cout << std::endl;

    std::cout << "insert 3" << std::endl;
    BST->insert(3);
    BST->printTree();
    std::cout << std::endl;

    std::cout << "remove 3" << std::endl;
    BST->remove(3);
    std::cout << "remove 7" << std::endl;
    BST->remove(7);
    std::cout << "is full: " << std::boolalpha << BST->isFull() << std::endl;
    BST->printTree();
    std::cout << std::endl;

    std::cout << "insert 3" << std::endl;
    BST->insert(3);
    std::cout << "insert 2" << std::endl;
    BST->insert(2);
    std::cout << "insert 1" << std::endl;
    BST->insert(1);
    BST->printTree();
    std::cout << std::endl;

    std::cout << "is balanced: " << std::boolalpha << BST->isBalanced() << std::endl;
    delete BST;
}

void TestCase::doTestAVLTree() {
    auto* AVL = new AVLTree();
    std::cout << "insert 1" << std::endl;
    AVL->insert(1);
    std::cout << "insert 2" << std::endl;
    AVL->insert(2);
    std::cout << "insert 3" << std::endl;
    AVL->insert(3);
    std::cout << "insert 7" << std::endl;
    AVL->insert(7);
    std::cout << "insert 10" << std::endl;
    AVL->insert(10);
    std::cout << "insert 4" << std::endl;
    AVL->insert(4);
    std::cout << "remove 1" << std::endl;
    AVL->remove(1);
    std::cout << "remove 2" << std::endl;
    AVL->remove(2);
    std::cout << std::endl;

    std::cout << "height: " << AVL->getHeight() << std::endl;
    std::cout << "max: " << AVL->getMax() << std::endl;
    std::cout << "min: " << AVL->getMin() << std::endl;
    std::cout << "contains 7: " << std::boolalpha << AVL->contains(7) << std::endl;
    std::cout << "contains 6: " << std::boolalpha << AVL->contains(6) << std::endl;
    std::cout << "is full: " << std::boolalpha << AVL->isFull() << std::endl;
    AVL->printTree();
    std::cout << std::endl;
    delete AVL;
}

void TestCase::testBinarySearchTree() {
    std::cout << std::endl << "<TEST BinarySearchTree>" << std::endl << std::endl;
    doTestBinarySearchTree();
}

void TestCase::testAVLTree() {
    std::cout << std::endl << "<TEST AVLTree>" << std::endl << std::endl;
    doTestAVLTree();
}

void TestCase::testMinHeap() {
    std::cout << std::endl << "<TEST MinHeap>" << std::endl << std::endl;
    doTestMinHeap();
}

void TestCase::doTestMinHeap() {
    auto* HEAP = new MinHeap(20);
    std::cout << "INSERT: 10, 5, 7, 1, 3, 20" << std::endl;
    HEAP->insert(10);
    HEAP->insert(5);
    HEAP->insert(7);
    HEAP->insert(1);
    HEAP->insert(3);
    HEAP->insert(20);
    std::cout << "EXTRACT MIN:" << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    std::cout << HEAP->extractMin() << std::endl;
    delete HEAP;
}

void TestCase::doTestQuickSort() {
    std::vector<int> array;
    array.push_back(5);
    array.push_back(3);
    array.push_back(2);
    array.push_back(6);
    array.push_back(10);
    array.push_back(-1);
    array.push_back(300);
    array.push_back(1);
    QuickSort::quickSort(array);
    for (auto i : array) {
        std::cout << i << std::endl;
    }
}

void TestCase::testQuickSort() {
    std::cout << std::endl << "<TEST QuickSort>" << std::endl << std::endl;
    doTestQuickSort();
}


