#include<iostream>
#include<vector>

#include<unordered_map>
using namespace std;

class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row(9), col(9), box(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char cur = board[i][j];
                    if(row[i][cur] > 0 || col[j][cur] > 0 || box[index(i, j)][cur] > 0){
                        return false;
                    }
                    row[i][cur]++;
                    col[j][cur]++;
                    box[index(i, j)][cur]++;
                }
            }
        }
        return true;
    }
     int index(int x, int y){
         int index1 = x / 3;
         int index2 = y / 3;
         return index1 * 3 + index2;
     }
};