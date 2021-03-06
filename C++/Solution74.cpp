#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size1 = matrix.size(), size2 = matrix[0].size();
        int row = 0, col = size2 - 1;
        while(matrix[row][col] != target){
            if(matrix[row][col] > target){
                col--;
                if(col < 0){
                    return false;
                }
            }
            else{
                row++;
                if(row == size1){
                    return false;
                }
            }
        }
        return true;
    }
};