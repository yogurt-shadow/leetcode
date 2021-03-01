#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution51 {
public:
    unordered_set<int> col, line1, line2;
    int size;

    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<vector<string>> res;
        vector<string> board;
        string str = "";
        for(int i = 0; i < n; i++){
            str += '.';
        }
        for(int i = 0; i < n; i++){
            board.push_back(str);
        }
        fill(res, board, 0);
        return res;
    }

    void fill(vector<vector<string>>& res, vector<string>& board, int index){
        for(int xx = 0; xx < size; xx++){
            board[index][xx] = 'Q';
            if(col.count(xx) > 0 || line1.count(index - xx) > 0 || line2.count(index + xx) > 0){
                board[index][xx] = '.';
                continue;
            }
            if(index == size - 1){
                vector<string> copy(board.begin(), board.end());
                res.push_back(copy);
                board[index][xx] = '.';
                return;
            }
            col.insert(xx);
            line1.insert(index - xx);
            line2.insert(index + xx);
            fill(res, board, index + 1);
            col.erase(col.find(xx));
            line1.erase(line1.find(index - xx));
            line2.erase(line2.find(index + xx));
            board[index][xx] = '.';
        }
    }
};

int main(){
    string x = "12312";
    cout << x << endl;
    x[2] = 'Q';
    cout << x << endl;
    return 0;
}