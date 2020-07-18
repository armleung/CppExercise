#include "../binary_search_tree/bst.h"
#include <vector>
#include <queue>

class binary_Search_tree;

class DFS {
    binary_Search_tree* ptr_bst;
    public:
        DFS(binary_Search_tree* bst = nullptr)
            :ptr_bst(bst)
        {}
        /*  Example Input 
                 50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
        */
        // InOrder Output (Left, Root, Right) (^): 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80
        void InOrder_base(std::vector<Node*>& result, Node* currentNode){
            if (currentNode->left != nullptr) InOrder_base(result,currentNode->left);
            result.push_back(currentNode);
            if (currentNode->right != nullptr) InOrder_base(result,currentNode->right);
            
        }
        std::vector<Node*> InOrder(){
            std::vector<Node*> result;
            if (ptr_bst == nullptr) return result;
            Node* root = ptr_bst->GetRoot();
            InOrder_base(result,root);
            return result;
        }
        /*  Example Input 
                 50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
        */
        // PreOrder Output (Root, Left, Right) (/_): 50 -> 30 -> 20 -> 40 -> 70 -> 60 -> 80
        void PreOrder_base(std::vector<Node*>& result, Node* currentNode){
            result.push_back(currentNode);
            if (currentNode->left != nullptr) PreOrder_base(result,currentNode->left);
            if (currentNode->right != nullptr) PreOrder_base(result,currentNode->right);
        }
        std::vector<Node*> PreOrder(){
            std::vector<Node*> result;
            if (ptr_bst == nullptr) return result;
            PreOrder_base(result,ptr_bst->GetRoot());
            return result;
        }
        /*  Example Input 
                 50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
        */
        // PostOrder Output (Left, Right, Root) (_\): 20 -> 40 -> 30 -> 60 -> 80 -> 70 -> 50
        void PostOrder_base(std::vector<Node*>& result, Node* currentNode){
            if (currentNode->left != nullptr) PostOrder_base(result,currentNode->left);
            if (currentNode->right != nullptr) PostOrder_base(result,currentNode->right);
            result.push_back(currentNode);
        }
        std::vector<Node*> PostOrder(){
            std::vector<Node*> result;
            if (ptr_bst == nullptr) return result;
            PostOrder_base(result,ptr_bst->GetRoot());
            return result;
        }
        /*  Example Input 
                 50          
              /     \        
             30      70     
            /  \    /  \   
           20   40  60   80  
        */
        // Output : 50 -> 20 -> 70 -> 20 -> 40 -> 60 -> 80 
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