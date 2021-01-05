//
// Created by jerryzhou3 on 1/4/2021.
//

#ifndef DATASTRUCTURES_AVLTREE_H
#define DATASTRUCTURES_AVLTREE_H

#include <cstdlib>
#include <iostream>
#include <queue>

class AVLTree {
    struct TreeNode {
        int val;
        int height;
        TreeNode* left;
        TreeNode* right;
        explicit TreeNode(int x): val(x), height(0), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right): val(x), height(0), left(left), right(right) {}
    };

    TreeNode* root;

    static TreeNode* leftRotate(TreeNode* root);
    static TreeNode* rightRotate(TreeNode* root);
    static TreeNode* leftRightRotate(TreeNode* root);
    static TreeNode* rightLeftRotate(TreeNode* root);
    static int getBalance(TreeNode* root);
    void balanceTree(int target);
    void updateHeight();

public:
    void insert(int x);
    bool contains(int x);
    int getMin();
    int getMax();
    int getHeight();
    void remove(int x);
    bool isFull();
    void printTree();
};


#endif //DATASTRUCTURES_AVLTREE_H
