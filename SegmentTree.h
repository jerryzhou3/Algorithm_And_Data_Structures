//
// Created by jerryzhou3 on 2021/7/24.
//

#ifndef CODING_AND_DATA_STRUCTURES_SEGMENTTREE_H
#define CODING_AND_DATA_STRUCTURES_SEGMENTTREE_H

#include <vector>
#include <algorithm>

class SegmentTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr) {}
        TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
        TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
    };

    TreeNode* root;
    std::vector<int> array;

public:
    SegmentTree(std::vector<int> array): root(nullptr) {
        sort(array.begin(), array.end());
        this->array = array;
    }
    SegmentTree(): root(nullptr), array(std::vector<int>()) {}
    void insert(int val);

private:
    void construct_tree_from_array();
    TreeNode* construct_tree_rec(std::vector<int>& array, int left, int right);
    void insert_and_sort_array(int val);
};

#endif //CODING_AND_DATA_STRUCTURES_SEGMENTTREE_H
