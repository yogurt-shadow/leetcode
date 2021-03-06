#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;


class Solution79 {
public:
    int a[4] = {-1, 1, 0, 0};
    int b[4] = {0, 0, -1, 1};
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    unordered_set<int> set;
                    if(dfs(i, j, board, word, 0, set)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int convert(int row, int col){
        return row * n + col;
    }

    bool dfs(int row, int col, vector<vector<char>>& board, string word, int index, unordered_set<int>& set){
        if(word[index] != board[row][col]){
            return false;
        }
        if(index == word.length() - 1){
            return true;
        }
        set.insert(convert(row, col));
        for(int indexx = 0; indexx < 4; indexx++){
           if(row + a[indexx] >= 0 && row + a[indexx] < m && col + b[indexx] >= 0 && col + b[indexx] < n){
               if(set.count(convert(row + a[indexx], col + b[indexx])) > 0){
                   continue;
                }
               if(dfs(row + a[indexx], col + b[indexx], board, word, index + 1, set)){
                    return true;
                }
            }
        }
        set.erase(set.find(convert(row, col)));
        return false;
    }
};

int main(){
    Solution79 s;
    vector<vector<char>> board = {{'a', 'b'}};
    string str = "ba";
    cout << s.exist(board, str);
    return 0;
}