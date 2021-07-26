//
// Created by jerryzhou3 on 2021/7/24.
//

#include "SegmentTree.h"

void SegmentTree::insert(int val) {
    this->insert_and_sort_array(val);
}

void SegmentTree::construct_tree_from_array() {
    this->root = this->construct_tree_rec(this->array, 0, this->array.size() - 1);
}

SegmentTree::TreeNode* SegmentTree::construct_tree_rec(std::vector<int> &arr, int left, int right) {
    int mid = (left + right) / 2;
    if (left == right) {
        TreeNode* newNode = new TreeNode(arr[mid]);
        return newNode;
    }
    else {
        TreeNode* newNode = new TreeNode();
        TreeNode* leftNode = this->construct_tree_rec(arr, left, mid);
        TreeNode* rightNode = this->construct_tree_rec(arr, mid + 1, right);
        newNode->val = leftNode->val + rightNode->val;
        newNode->left = leftNode;
        newNode->right = rightNode;
        return newNode;
    }
}

void SegmentTree::insert_and_sort_array(int val) {
    if (this->array.empty()) {
        this->array.push_back(val);
    }
    else {
        auto it = this->array.begin();
        while (it != this->array.end() && *it <= val) ++it;
        this->array.insert(it, val);
    }
}