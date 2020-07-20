#include "Minesweeper.h"
#include <vector>
#include <iostream>

int main(){
    std::vector<std::vector<char>> board{
                                            {'E','E','E','E','E'},
                                            {'E','E','M','E','E'},
                                            {'E','E','E','E','E'},
                                            {'E','E','E','E','E'}
                                        };
    std::vector<int> click({0,0});
    
    Solution s;
    std::vector<std::vector<char>> result = s.updateBoard(board,click);

    for (auto it : result){
        for (auto itt : it){
            std::cout << itt << " ";
        }
        std::cout << std::endl;
    }
}