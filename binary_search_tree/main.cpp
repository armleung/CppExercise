#include "bst.h"

/* 
        50          
    /     \        
    30      70     
    /  \    /  \   
    20   40  60   80  
*/

int main() {
    binary_Search_tree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    std::cout << "Original Tree" << std::endl;
    tree.DebugPrint();
    std::cout << "Removing 20 (leaf)" << std::endl;
    tree.remove(20); // Case 1
    tree.DebugPrint();
    std::cout << "Removing 30 (Have one child)" << std::endl;
    tree.remove(30); // Case 2
    tree.DebugPrint();
    std::cout << "Removing 50 (Have two child)" << std::endl;
    tree.remove(50); // Case 3
    tree.DebugPrint();
    return 0;
}