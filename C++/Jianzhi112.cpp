#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> dp;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        dp.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]){
            return dp[i][j];
        }
        int cur = 1;
        for(int k = 0; k < 4; k++){
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if(ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j]){
                cur = max(cur, 1 + dfs(matrix, ni, nj));
            }
        }
        return dp[i][j] = cur;
    }
};