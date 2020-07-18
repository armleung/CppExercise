#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <queue> 

class Node {
    public:
        Node(int input_value){
            left = nullptr;
            right = nullptr;
            value = input_value; }
        ~Node(){
            //if (left != nullptr) {delete left; left = nullptr;}
            //if (right != nullptr) {delete right; right = nullptr;}
        }

        void DebugPrint(){
            std::cout << "Node Value : " << value << " ";
            if (left != nullptr) std::cout << "Left Node Value : " << left->value << " ";
            if (right != nullptr) std::cout << "Left Node Value : " << right->value << " ";
            std::cout << std::endl;
        }

        int value;
        Node* left;
        Node* right;
};

class binary_Search_tree{
    public:
        binary_Search_tree() {
            root = nullptr;
        }
        Node* GetRoot(){
            return root;
        }
        void insert(int value){
            Node* newNode = new Node(value);
            if (root == nullptr){
                root = newNode;
            } else {
                Node* currentNode = root;
                while (true){
                    if (value < currentNode->value) {// Should go left
                        if (currentNode->left == nullptr){
                            currentNode->left = newNode;
                            return ;
                        }
                        currentNode = currentNode->left;
                    } else {
                        if (currentNode->right == nullptr){
                            currentNode->right = newNode;
                            return ;
                        }
                        currentNode = currentNode->right;
                    }
                }
            }
        }
        bool lookup(int value){
            if (root == nullptr) return false;
            Node* currentNode = root;
            while (currentNode != nullptr){
                if (currentNode->value == value ) return true;
                else if (value < currentNode->value) {
                    currentNode = currentNode->left;
                } else currentNode = currentNode->right;
            }
            return false;
        }

        // 1) Node to be deleted is leaf: Simply remove from the tree.
        /*
                   50                            50
                /     \         delete(20)      /   \
                30      70       --------->    30     70 
                /  \    /  \                     \    /  \ 
              20   40  60   80                   40  60   80
        */
        // 2) Node to be deleted has only one child: Copy the child to the node and delete the child
        /*
                   50                             50
                /     \         delete(30)      /   \
                30      70       --------->    40     70 
                  \    /  \                          /  \ 
                  40  60   80                       60   80
        */
        // 3) Node to be deleted has two children: Find inorder successor of the node. 
        // Copy contents of the inorder successor to the node and delete the inorder successor. 
        // Note that inorder predecessor can also be used.
        /*
                   50                            60
                /     \         delete(50)      /   \
               40      70       --------->    40    70 
                        /  \                            \ 
                       60   80                           80
        */
        void remove(int value){
            if (root == nullptr) return;
            Node* currentNode = root;
            Node* parentNode = nullptr;
            while (currentNode != nullptr){
                if (currentNode->value == value ) {
                    if (currentNode->left == nullptr && currentNode->right == nullptr){ // Case 1
                        if (parentNode->left->value == value) {delete currentNode; parentNode->left = nullptr;}
                        if (parentNode->right->value == value) {delete currentNode; parentNode->right = nullptr;}
                    } else if (currentNode->left != nullptr && currentNode->right != nullptr){ // Case 3, two child                         
                        Node* minNode = minValueNode(currentNode->right);
                        currentNode->value = minNode->value;
                        delete minNode;
                    }
                    else { 
                        if (currentNode->left != nullptr){  // Case 2 , one child (left)
                            if (parentNode->left->value == value) {
                                parentNode->left = currentNode->left;
                                delete currentNode;
                            } else {
                                parentNode->right = currentNode->left;
                                delete currentNode;
                            }
                        }  
                        else if (currentNode->right != nullptr){  // Case 2 , one child (right)
                            if (parentNode->left->value == value) {
                                parentNode->left = currentNode->right;
                                delete currentNode;
                            } else {
                                parentNode->right = currentNode->right;
                                delete currentNode;
                            }
                        } 
                    }
                }
                else if (value < currentNode->value) {
                    parentNode = currentNode;
                    currentNode = currentNode->left;
                } else {
                    parentNode = currentNode;
                    currentNode = currentNode->right;
                }
            }
        }

        void DebugPrint(){
            if (root == nullptr) return;

            std::queue<Node*> processingNode;
            processingNode.push(root);

            while(!processingNode.empty()){
                Node* currentNode = processingNode.front();
                processingNode.pop();

                std::cout << " " << currentNode->value ;
                if (currentNode->left != nullptr) {
                    processingNode.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    processingNode.push(currentNode->right);
                }
            }
            std::cout << std::endl;
        }
    private: 
        Node* root;
        Node* minValueNode(Node* node) 
        { 
            Node* current = node; 
            /* loop down to find the leftmost leaf */
            while (current && current->left != nullptr) {
                current = current->left; 
            }
            return current; 
        } 
};

#endif