#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution576_2 {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(m, n, maxMove, startRow, startColumn);
    }

    int dfs(int m, int n, int move, int row, int col){
        if (row < 0 || row >= m || col < 0 || col >= n){
            return 1;
        }
        if(dp[move][row][col] != -1){
            return dp[move][row][col];
        }
        if(move == 0){
            return 0;
        }
        ll cur = 0;
        for(int i = 0; i < 4; i++){
            cur += dfs(m, n, move - 1, row + dir[i][0], col + dir[i][1]);
        }
        return dp[move][row][col] = cur % MOD;
    }
};