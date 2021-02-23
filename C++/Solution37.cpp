#include<iostream>
#include<vector>

#include<unordered_map>
using namespace std;

class Solution37 {
public:
    vector<pair<int, int>> set;
    int size;
    vector<unordered_map<char, int>> row, col, box;

    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9); col.resize(9); box.resize(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    set.push_back({i, j});
                }
                else{
                    char cur = board[i][j];
                    row[i][cur]++;
                    col[j][cur]++;
                    box[index(i, j)][cur]++;
                }
            }
        }
        size = set.size();
        fill(board, 0);
    }

    bool fill(vector<vector<char>>& board, int cur){
        pair<int, int> position = set[cur];
        int xx = position.first, yy = position.second;
        for(char ele = '1'; ele <= '9'; ele++){
            if(row[xx][ele] > 0 || col[yy][ele] > 0 || box[index(xx, yy)][ele] > 0) {
                continue;
            }
            board[xx][yy] = ele;
            row[xx][ele]++; col[yy][ele]++; box[index(xx, yy)][ele]++;
            if(cur == size - 1){
                return true;
            }
            if(fill(board, cur + 1)){
                return true;
            }
            board[xx][yy] = '.';
            row[xx][ele]--; col[yy][ele]--; box[index(xx, yy)][ele]--;
        }
        return false;
    }

    int index(int x, int y){
        int index1 = x / 3, index2 = y / 3;
        return index1 * 3 + index2;
    }
};

void print(vector<vector<char>>& matrix){
    for(int index = 0; index < 25; index++){
            cout << "-";
        }
    cout << endl;
    for(int row = 0; row < 9; row++){
        cout << "| ";
        for(int col = 0; col < 9; col++){
            cout << matrix[row][col];
            if((col + 1) % 3 == 0){
                cout << " |";
            }
            cout << " ";
        }
        cout << endl;
        if((row + 1) % 3 == 0){
            for(int index = 0; index < 25; index++){
                cout << "-";
            }
            cout << endl;
        }
    }
}

void print_solve(vector<vector<char>> matrix){
    vector<vector<char>> solve(matrix.begin(), matrix.end());
    Solution37 s;
    s.solveSudoku(solve); 
    for(int index = 0; index < 25; index++){
            cout << "-";
    }
    for(int index = 0; index < 10; index++){
            cout << " ";
    }
    for(int index = 0; index < 25; index++){
        cout << "-";
    }
    cout << endl;
    for(int row = 0; row < 9; row++){
        cout << "| ";
        for(int col = 0; col < 9; col++){
            cout << matrix[row][col];
            if((col + 1) % 3 == 0){
                cout << " |";
            }
            cout << " ";
        }
        for(int index = 0; index < 10; index++){
            cout << " ";
        }
        cout << "| ";
        for(int col = 0; col < 9; col++){
            cout << solve[row][col];
            if((col + 1) % 3 == 0){
                cout << " |";
            }
            cout << " ";
        }
        cout << endl;
        if((row + 1) % 3 == 0){
            for(int index = 0; index < 25; index++){
                cout << "-";
            }
            for(int index = 0; index < 11; index++){
                 cout << " ";
            }
            for(int index = 0; index < 25; index++){
                cout << "-";
            }
            cout << endl;
        }
    }
}

int main(){
    vector<vector<char>> matrix = {
       {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
       {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
       {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
       {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
       {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
       {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
       {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
       {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
       {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    print_solve(matrix);
}