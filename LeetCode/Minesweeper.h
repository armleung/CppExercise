#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[1];
        int y = click[0];
        int ylimit = board.size();
        int xlimit = board[0].size();

        std::cout << "xlimit : " << xlimit << " ,ylimit : " << ylimit << std::endl;
        
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return board;
        }
                
        std::queue<vector<int>> q;
        std::set<vector<int>> duplicate;
        q.push(click);
        
        while (!q.empty()){
            vector<int> currentClick = q.front(); q.pop();
            // Check duplicate 
            if (duplicate.find(currentClick) != duplicate.end()){
                continue;
            }
            duplicate.insert(currentClick);

            std::cout << "Current Click : " << currentClick[1] << ", " << currentClick[0] << std::endl;
            
            vector<vector<int>> adjacents = findAdjacent(currentClick,xlimit,ylimit);
            int count = 0;
            for (auto&& xy : adjacents){
                if (board[xy[0]][xy[1]] == 'M') count++;
            }

            if (count > 0) board[currentClick[0]][currentClick[1]] = '0' + count;
            else {
                board[currentClick[0]][currentClick[1]] = 'B';
                for (auto&& xy : adjacents){
                    q.push(xy);
                }
            }
        }
        
        return board;
    }
    
    vector<vector<int>> findAdjacent(vector<int>& click, int xlimit, int ylimit){
        int x = click[1];
        int y = click[0];
        
        vector<vector<int>> result;
        result.push_back({y-1,x-1});
        result.push_back({y,x-1});
        result.push_back({y+1,x-1});
        result.push_back({y-1,x});
        result.push_back({y+1,x});
        result.push_back({y-1,x+1});
        result.push_back({y,x+1});
        result.push_back({y+1,x+1});

        result.erase(std::remove_if(result.begin(), 
                            result.end(),
                            [xlimit, ylimit](vector<int> x){return x[0] < 0 || x[0] >= ylimit || x[1] < 0 || x[1] >= xlimit ;}),
            result.end());

        std::cout << "Debug Print:" << std::endl;
        for (auto&& xy : result){
            std::cout << "x: " << xy[1] << " ,y: " << xy[0] << std::endl;
        }
        return result;
    }
};