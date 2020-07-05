#include <iostream> 
#include "linked_list.h"

// 10 -> 5 -> 6 -> 7
// 10 -> 5 -> 7
int main(){
    LinkedList<int> test;
    test.append(5);
    test.append(6);
    test.prepend(10);
    test.append(7);
    test.remove(6);
    std::cout << test.DebugPrint();
    return 0;
}