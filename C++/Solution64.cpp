#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int x = m - 2; x >= 0; x--){
            dp[x][n - 1] = grid[x][n - 1] + dp[x + 1][n - 1];
        }
        for(int y = n - 2; y >= 0; y--){
            dp[m - 1][y] = grid[m - 1][y] + dp[m - 1][y + 1];
        }
        for(int x = m - 2; x >= 0; x--){
            for(int y = n - 2; y >= 0; y--){
                dp[x][y] = grid[x][y] + min(dp[x + 1][y], dp[x][y + 1]);
            }
        }
        return dp[0][0];
    }
};