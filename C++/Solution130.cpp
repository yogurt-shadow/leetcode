#include<iostream>
#include<vector>

#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution130 {
public:
    int n, m;
    unordered_set<int> set;
    int xx[4] = {-1, 1, 0, 0};
    int yy[4] = {0, 0, -1, 1};

    int convert(int row, int col){
        return row * m + col;
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        set.insert(convert(x, y));
        for(int i = 0; i < 4; i++){
            int curx = x + xx[i], cury = y + yy[i];
            if(curx >= 0 && curx < n && cury >= 0 && cury < m && board[curx][cury] == 'O' && set.count(convert(curx, cury)) == 0){
                dfs(board, curx, cury);
            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][m - 1] == 'O'){
                dfs(board, i, m - 1);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[n - 1][i] == 'O'){
                dfs(board, n - 1, i);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && set.count(convert(i, j)) == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};