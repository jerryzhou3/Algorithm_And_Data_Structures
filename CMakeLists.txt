cmake_minimum_required(VERSION 3.17)
project(DataStructures)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructures main.cpp BinarySearchTree.cpp BinarySearchTree.h TestCase.cpp TestCase.h AVLTree.cpp AVLTree.h MinHeap.cpp MinHeap.h QuickSort.cpp QuickSort.h SegmentTree.cpp SegmentTree.h)