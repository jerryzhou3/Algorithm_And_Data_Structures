#include <iostream>
#include "BinarySearchTree.h"

int main() {
    auto* BST = new BinarySearchTree();
    BST->insert(5);
    BST->insert(3);
    BST->insert(10);
    BST->insert(7);
    BST->insert(4);
    std::cout << "height: " << BST->getHeight() << std::endl;
    std::cout << "max: " << BST->getMax() << std::endl;
    std::cout << "min: " << BST->getMin() << std::endl;
    std::cout << "contains 7: " << std::boolalpha << BST->contains(7) << std::endl;
    std::cout << "contains 6: " << std::boolalpha << BST->contains(6) << std::endl;
    std::cout << "is full: " << std::boolalpha << BST->isFull() << std::endl;
    BST->printTree();
    std::cout << "remove 3" << std::endl;
    BST->remove(3);
    BST->printTree();
    std::cout << "insert 3" << std::endl;
    BST->insert(3);
    BST->printTree();
    std::cout << "remove 3" << std::endl;
    BST->remove(3);
    std::cout << "remove 7" << std::endl;
    BST->remove(7);
    std::cout << "is full: " << std::boolalpha << BST->isFull() << std::endl;
    BST->printTree();
    return 0;
}
