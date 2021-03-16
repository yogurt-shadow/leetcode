#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution1275 {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        for(int i = 0; i < moves.size(); i++){
            char sign = (i % 2 == 0) ? 'X' : 'O';
            board[moves[i][0]][moves[i][1]] = sign;
        }
        for(int i = 0; i < 3; i++){
            char cur = board[i][0];
            if(cur == ' '){
                continue;
            }
            bool win = true;
            for(int j = 0; j < 3; j++){
                if(board[i][j] != cur){
                    win = false;
                    break;
                }
            }
            if(win){
                return cur == 'X' ? "A" : "B";
            }
        }

        for(int i = 0; i < 3; i++){
            char cur = board[0][i];
            if(cur == ' '){
                continue;
            }
            bool win = true;
            for(int j = 0; j < 3; j++){
                if(board[j][i] != cur){
                    win = false;
                    break;
                }
            }
            if(win){
                return cur == 'X' ? "A" : "B";
            }
        }
        char cur = board[0][0];
        bool win = true;
        if(cur == ' '){
            win = false;
        }
        for(int i = 1; i < 3; i++){
            if(board[i][i] != cur){
                win = false;
                break;
            }
        }
        if(win){
            return cur == 'X' ? "A" : "B";
        }
        cur = board[0][2];
        win = true;
        if(cur == ' '){
            win = false;
        }
        for(int i = 1; i < 3; i++){
            if(board[i][2 - i] != cur){
                win = false;
                break;
            }
        }
        if(win){
            return cur == 'X' ? "A" : "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};