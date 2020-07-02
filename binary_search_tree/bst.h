#include <iostream>
#include <queue> 

class Node {
    public:
        Node(int input_value){
            left = nullptr;
            right = nullptr;
            value = input_value; }
        ~Node(){
            if (left != nullptr) {delete left;}
            if (right != nullptr) {delete right;}
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
        void test(){
            std::cout << "Hello BST" << std::endl;
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
        }
    private: 
        Node* root;
};

