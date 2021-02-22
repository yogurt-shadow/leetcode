#include<iostream>
#include<vector>

using namespace std;

class Solution807 {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> row(m), col(m);
        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                cur = max(cur, grid[i][j]);
            }
            row[i] = cur;
        }

        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                cur = max(cur, grid[j][i]);
            }
            col[i] = cur;
        }
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                int cur = min(row[i], col[j]);
                result += cur - grid[i][j];
            }
        }
        return result;
    }
};