#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);
        for(int index = 0; index < n; index++){
                res[index] = matrix[0][index];
        }
        if(m == 1){
            return res;
        }
        vector<vector<int>> rotate(n, vector<int>(m - 1));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m - 1; col++){
                rotate[row][col] = matrix[1 + col][n - 1 - row];
            }
        }
        vector<int> other = spiralOrder(rotate);
        for(int index = n; index < m * n; index++){
            res[index] = other[index - n];
        }
        return res;
    }
};