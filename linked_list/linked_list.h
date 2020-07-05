#include "list_element.h"
#include <string>
#include <sstream>

template <class T>
class LinkedList {
    public:
        LinkedList() : head_(nullptr){}
        ~LinkedList(){}
        LinkedList(const LinkedList&) = delete;

        void append(const T &value){
            ListElement<T> *newNode = new ListElement<T>(value);

            if (head_ == nullptr) {
                head_ = newNode; return ;
            }else {
                ListElement<T> *currentPointer = head_;
                while (currentPointer->GetNext() != nullptr){
                    currentPointer = currentPointer->GetNext();
                }
                currentPointer->SetNext(new ListElement<T>(value));
            }
        }

        void prepend(const T &value){
            ListElement<T> *newNode = new ListElement<T>(value);
            if (head_ == nullptr) {
                head_ = newNode; return ;
            }
            ListElement<T> *headPointer = head_;
            newNode->SetNext(headPointer);
            head_ = newNode;
        }

        void remove(const T &value){
            if (head_->GetData() == value){
                ListElement<T> *temp = head_;
                head_ = head_->GetNext();
                delete temp;
                return;
            }
            ListElement<T> *previousPointer = head_;
            ListElement<T> *currentPointer = head_->GetNext();

            while (currentPointer != nullptr){
                if (currentPointer->GetData() == value){
                    // Node Found , remove this 
                    previousPointer->SetNext(currentPointer->GetNext());
                    delete currentPointer;
                    return;
                }else{
                    previousPointer = currentPointer;
                    currentPointer = currentPointer->GetNext();
                }
            }
        }

        std::string DebugPrint(){
            if (head_ == nullptr) return "No Element Inside";
            ListElement<T> *currentPointer = head_;
            std::stringstream ss;
            ss << currentPointer->GetData();
            currentPointer = currentPointer->GetNext();
            while (currentPointer != nullptr){
                ss << " -> " << currentPointer->GetData();
                currentPointer = currentPointer->GetNext();
            }
            return ss.str();
        }
    private:
        ListElement<T> *head_;          
};