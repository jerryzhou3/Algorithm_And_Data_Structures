//
// Created by jerryzhou3 on 1/4/2021.
//

#include "BinarySearchTree.h"


void BinarySearchTree::insert(int x) {
    TreeNode* temp = this->root;
    TreeNode* prev = nullptr;
    while (temp) {
        prev = temp;
        if (temp->val == x) return;
        else if (temp->val < x) temp = temp->right;
        else temp = temp->left;
    }
    auto* node = new TreeNode(x);
    if (!prev) this->root = node;
    else {
        if (prev->val > x) prev->left = node;
        else prev->right = node;
    }
}

bool BinarySearchTree::contains(int x) {
    TreeNode* temp = this->root;
    while (temp) {
        if (temp->val == x) return true;
        else if (temp->val < x) temp = temp->right;
        else temp = temp->left;
    }
    return false;
}

int BinarySearchTree::getMin() {
    if (!this->root) return 0;
    TreeNode* temp = this->root;
    while (temp->left) {
        temp = temp->left;
    }
    return temp->val;
}

int BinarySearchTree::getMax() {
    if (!this->root) return 0;
    TreeNode* temp = this->root;
    while (temp->right) {
        temp = temp->right;
    }
    return temp->val;
}

int BinarySearchTree::getHeight() {
    struct recursion {
        static int getHeight_rev(TreeNode* root) {
            if (!root) return 0;
            else return 1 + std::max(getHeight_rev(root->left), getHeight_rev(root->right));
        }
    };
    return recursion::getHeight_rev(this->root);
}

void BinarySearchTree::remove(int x) {
    TreeNode* temp = this->root;
    TreeNode* prev = nullptr;
    while (temp && temp->val != x) {
        prev = temp;
        if (temp->val < x) temp = temp->right;
        else temp = temp->left;
    }
    if (!temp) return;
    if (!prev) {
        delete this->root;
        this->root = nullptr;
        return;
    }
    if (prev->val < temp->val) {
        if (temp->left && temp->right) {
            prev->right = temp->left;
            temp->left->right = temp->right;
        }
        else if (temp->left) prev->right = temp->left;
        else if (temp->right) prev->right = temp->right;
        else prev->right = nullptr;
    }
    else {
        if (temp->left && temp->right) {
            prev->left = temp->right;
            temp->right->left = temp->left;
        }
        else if (temp->left) prev->left = temp->left;
        else if (temp->right) prev->left = temp->right;
        else prev->left = nullptr;
    }
    delete temp;
}

bool BinarySearchTree::isFull() {
    struct recursion{
        static bool isFull_rec(TreeNode* root) {
            if (!root) return true;
            if (!root->left == !root->right) return isFull_rec(root->left) && isFull_rec(root->right);
            else return false;
        }
    };
    return recursion::isFull_rec(this->root);
}

bool BinarySearchTree::isBalanced() {
    return false;
}

void BinarySearchTree::printTree() {
    if (!this->root) std::cout << "Empty Tree" << std::endl;
    std::cout << "Print Tree: " << std::endl;
    std::queue<TreeNode*> q;
    q.push(this->root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (i < size - 1) {
                if (!node) std::cout << "null ";
                else std::cout << node->val << " ";
            }
            else {
                if (!node) std::cout << "null" << std::endl;
                else std::cout << node->val << std::endl;
            }
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
}