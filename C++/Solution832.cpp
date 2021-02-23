#include<iostream>
#include<vector>

using namespace std;

class Solution832 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> res(m, vector<int>(m));
        for(int row = 0; row < m; row++){
            for(int j = 0; j < m; j++){
                res[row][m - 1 - j] = 1 - A[row][j];
            }
        }
        return res;
    }
};