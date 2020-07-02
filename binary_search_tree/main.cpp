#include "bst.h"

//     9
//  4     20
//1  6  15  170

int main() {
    binary_Search_tree tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);
    if (tree.lookup(150)){
        std::cout << "Element Found";
    } else {
        std::cout << "Not Found";
    }
    return 0;
}