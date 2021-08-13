#include<iostream>
#include<vector>

using namespace std;

class Solution2 {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        return isValid(board, rMove, cMove);
    }

    int dir1[2] = {-1, 1};

    bool isValid(vector<vector<char>> &board, int rMove, int cMove){
        char color = board[rMove][cMove];
        char other = 'B' + 'W' - color;
        int num = 1;
        for(int i = 0; i < 2; i++){
            num = 1;
            for(int x = rMove + dir1[i]; x >= 0 && x < board.size(); x += dir1[i]){
                char cur = board[x][cMove];
                num ++;
                if(cur == other){
                    continue;
                }
                else if(cur == '.'){
                    break;
                }
                else{
                    if(num >= 3){
                        return true;
                    }
                    break;
                }
            }
        }
        num = 1;
        for (int i = 0; i < 2; i++)
        {
            num = 1;
            for (int y = cMove + dir1[i]; y >= 0 && y < board[0].size(); y += dir1[i])
            {
                char cur = board[rMove][y];
                num++;
                if (cur == other)
                {
                    continue;
                }
                else if (cur == '.')
                {
                    break;
                }
                else
                {
                    if (num >= 3)
                    {
                        return true;
                    }
                    break;
                }
            }
        }
        num = 1;
        for(int i = 0; i < 2; i++){
            num = 1;
            for(int x = rMove + dir1[i], int y = cMove + dir1[i]; x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
            x += dir1[i], y += dir1[i]){
                char cur = board[x][y];
                num++;
                if (cur == other)
                {
                    continue;
                }
                else if (cur == '.')
                {
                    break;
                }
                else
                {
                    if (num >= 3)
                    {
                        return true;
                    }
                    break;
                }
            }
        }
        num = 1;
        for (int i = 0; i < 2; i++)
        {
            num = 1;
            for (int x = rMove + dir1[i], int y = cMove + dir1[1 - i]; x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
                 x += dir1[i], y += dir1[1 - i])
            {
                char cur = board[x][y];
                num++;
                if (cur == other)
                {
                    continue;
                }
                else if (cur == '.')
                {
                    break;
                }
                else
                {
                    if (num >= 3)
                    {
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
};