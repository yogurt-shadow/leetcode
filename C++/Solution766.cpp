#include<iostream>
#include<vector>

using namespace std;

class Solution766 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int row = m - 2; row >= 0; row--){
            int cur = matrix[row][0];
            for(int index = 1; row + index < m && index < n; index++){
                if(matrix[row + index][index] != cur){
                    return false;
                }
            }
        }
        for(int col = 1; col < n - 1; col++){
            int cur = matrix[0][col];
            for(int index = 1; index < m && col + index < n; index++){
                if(matrix[index][col + index] != cur){
                    return false;
                }
            }
        }
        return true;
    }
};