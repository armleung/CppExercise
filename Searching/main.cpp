//#include "../binary_search_tree/bst.h"
#include "bfs.h"
#include "dfs.h"
/* 
        50          
    /     \        
    30      70     
    /  \    /  \   
    20   40  60   80  
*/


int main() {
    binary_Search_tree* tree = new binary_Search_tree();
    tree->insert(50);
    tree->insert(30);
    tree->insert(70);
    tree->insert(20);
    tree->insert(40);
    tree->insert(60);
    tree->insert(80);

    BFS Traversal(tree);
    std::vector<Node*> result = Traversal.LevelOrderTreeTraversal();
    std::cout << "Level Order Tree Traversal : ";
    for (auto it = result.begin() ; it != result.end() ; ++it){
       std::cout << (*it)->value << "->";
    }
    std::cout << "tail" << std::endl;

    DFS DFS_Traversal(tree);
    result = DFS_Traversal.InOrder();
    std::cout << "In Order Tree Traversal : ";
    for (auto it = result.begin() ; it != result.end() ; ++it){
       std::cout << (*it)->value << "->";
    }
    std::cout << "tail" << std::endl;

    result = DFS_Traversal.PreOrder();
    std::cout << "Pre Order Tree Traversal : ";
    for (auto it = result.begin() ; it != result.end() ; ++it){
       std::cout << (*it)->value << "->";
    }
    std::cout << "tail" << std::endl;

    result = DFS_Traversal.PostOrder();
    std::cout << "Post Order Tree Traversal : ";
    for (auto it = result.begin() ; it != result.end() ; ++it){
       std::cout << (*it)->value << "->";
    }
    std::cout << "tail" << std::endl;
    return 0;
}