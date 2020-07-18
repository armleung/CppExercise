#include "../binary_search_tree/bst.h"
#include <vector>
#include <queue>

class binary_Search_tree;

class BFS {
    binary_Search_tree* ptr_bst;
    public:
        BFS(binary_Search_tree* bst = nullptr)
            :ptr_bst(bst)
        {}
        /*  Example Input 
                 50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
        */
        // Output : 50 -> 30 -> 70 -> 20 -> 40 -> 60 -> 80 
        std::vector<Node*> LevelOrderTreeTraversal(){
            
            std::vector<Node*> result;
            std::queue<Node*> queue;
            if (ptr_bst == nullptr) return result;
            Node* root = ptr_bst->GetRoot();
            queue.push(root);
            
            while (queue.size() > 0){
                Node* currentNode = queue.front();
                queue.pop();
                result.push_back(currentNode);

                if (currentNode->left != nullptr) queue.push(currentNode->left);
                if (currentNode->right != nullptr) queue.push(currentNode->right);
            }

            return result;
        }
};