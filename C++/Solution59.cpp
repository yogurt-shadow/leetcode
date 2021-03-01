#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        return generate(1, n * n, n, n);
    }

    vector<vector<int>> generate(int start, int end, int row, int col){
        vector<vector<int>> res(row, vector<int>(col));
        for(int i = 0; i < col; i++){
            res[0][i] = start + i;
        }
        if(row == 1){
            return res;
        }
        vector<vector<int>> other = generate(start + col, end, col, row - 1);
        for(int xx = 1; xx < row; xx++){
            for(int yy = 0; yy < col; yy++){
                res[xx][yy] = other[col - 1 - yy][xx - 1];
            }
        }
        return res;
    }
};