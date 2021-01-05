//
// Created by jerryzhou3 on 1/4/2021.
//

#include "AVLTree.h"

AVLTree::TreeNode* AVLTree::leftRotate(TreeNode* root) {
    TreeNode* temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    return temp;
}

AVLTree::TreeNode* AVLTree::rightRotate(TreeNode* root) {
    TreeNode* temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    return temp;
}

AVLTree::TreeNode* AVLTree::leftRightRotate(TreeNode* root) {
    TreeNode* leftRoot = leftRotate(root->left);
    root->left = leftRoot;
    return rightRotate(root);
}

AVLTree::TreeNode* AVLTree::rightLeftRotate(TreeNode* root) {
    TreeNode* rightRoot = rightRotate(root->right);
    root->right = rightRoot;
    return leftRotate(root);
}

int AVLTree::getBalance(TreeNode* root) {
    if (!root) return 0;
    else {
        int leftHeight = 0;
        int rightHeight = 0;
        if (root->left) leftHeight = root->left->height;
        if (root->right) rightHeight = root->right->height;
        return rightHeight - leftHeight;
    }
}

void AVLTree::balanceTree(int target) {
    TreeNode* temp = this->root;
    TreeNode* prev = nullptr;
    TreeNode* unbalanced = nullptr;
    TreeNode* unbalancedPrev = nullptr;
    int balance = 0;
    while (temp && temp->val != target) {
        int cur_balance = getBalance(temp);
        if (cur_balance > 1 || cur_balance < -1) {
            unbalanced = temp;
            unbalancedPrev = prev;
            balance = cur_balance;
        }
        prev = temp;
        if (temp->val > target) temp = temp->left;
        else temp = temp->right;
    }

    if (unbalanced) {
        std::cout << "balance tree" << std::endl;
        TreeNode* balancedRoot;
        if (balance > 1) {
            int subBalance = getBalance(unbalanced->right);
            if (subBalance >= 0) {
                balancedRoot = leftRotate(unbalanced);
            }
            else {
                balancedRoot = rightLeftRotate(unbalanced);
            }
        }
        else {
            int subBalance = getBalance(unbalanced->left);
            if (subBalance <= 0) {
                balancedRoot = rightRotate(unbalanced);
            }
            else {
                balancedRoot = leftRightRotate(unbalanced);
            }
        }
        if (!unbalancedPrev) this->root = balancedRoot;
        else {
            if (balancedRoot->val < unbalancedPrev->val) unbalancedPrev->left = balancedRoot;
            else unbalancedPrev->right = balancedRoot;
        }
    }
}

void AVLTree::updateHeight() {
    struct recursion {
        static void updateHeight_rec(TreeNode* root) {
            if (!root) return;
            else {
                updateHeight_rec(root->left);
                updateHeight_rec(root->right);
                int leftHeight = 0;
                int rightHeight = 0;
                if (root->left) leftHeight = root->left->height;
                if (root->right) rightHeight = root->right->height;
                root->height = 1 + std::max(leftHeight, rightHeight);
                return;
            }
        }
    };
    recursion::updateHeight_rec(this->root);
}


void AVLTree::insert(int x) {
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

    updateHeight();
    balanceTree(x);
    updateHeight();
}

bool AVLTree::contains(int x) {
    TreeNode* temp = this->root;
    while (temp) {
        if (temp->val == x) return true;
        else if (temp->val < x) temp = temp->right;
        else temp = temp->left;
    }
    return false;
}

int AVLTree::getMin() {
    if (!this->root) return 0;
    TreeNode* temp = this->root;
    while (temp->left) {
        temp = temp->left;
    }
    return temp->val;
}

int AVLTree::getMax() {
    if (!this->root) return 0;
    TreeNode* temp = this->root;
    while (temp->right) {
        temp = temp->right;
    }
    return temp->val;
}

int AVLTree::getHeight() {
    if (!this->root) return 0;
    else return this->root->height;
}

void AVLTree::remove(int x) {
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

    updateHeight();
    balanceTree(x);
    updateHeight();
}

bool AVLTree::isFull() {
    struct recursion{
        static bool isFull_rec(TreeNode* root) {
            if (!root) return true;
            if (!root->left == !root->right) return isFull_rec(root->left) && isFull_rec(root->right);
            else return false;
        }
    };
    return recursion::isFull_rec(this->root);
}

void AVLTree::printTree() {
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