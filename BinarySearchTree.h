//
// Created by jerryzhou3 on 1/4/2021.
//

#ifndef DATASTRUCTURES_BINARYSEARCHTREE_H
#define DATASTRUCTURES_BINARYSEARCHTREE_H

#include <cstdlib>
#include <iostream>
#include <queue>

class BinarySearchTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
    };

    TreeNode* root;

public:
    BinarySearchTree(): root(nullptr) {};
    void insert(int x);
    bool contains(int x);
    int getMin();
    int getMax();
    int getHeight();
    void remove(int x);
    bool isFull();
    bool isBalanced();
    void printTree();
};


#endif //DATASTRUCTURES_BINARYSEARCHTREE_H
