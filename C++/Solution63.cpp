#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }
        vector<vector<long>> dp(m, vector<long>(n));
        dp[m - 1][n - 1] = 1;
        for(int y = n - 2; y >= 0; y--){
            if(obstacleGrid[m - 1][y] == 0){
                dp[m - 1][y] = dp[m - 1][y + 1];
            }
            else{
                dp[m - 1][y] = 0;
            }
        }
        for(int x = m - 2; x >= 0; x--){
            if(obstacleGrid[x][n - 1] == 0){
                dp[x][n - 1] = dp[x + 1][n - 1];
            }
            else{
                dp[x][n - 1] = 0;
            }
        }
        for(int y = n - 2; y >= 0; y--){
            for(int x = m - 2; x >= 0; x--){
                if(obstacleGrid[x][y] == 0){
                    dp[x][y] = dp[x + 1][y] + dp[x][y + 1];
                }
                else{
                    dp[x][y] = 0;
                }
            }
        }
        return dp[0][0];
    }
};