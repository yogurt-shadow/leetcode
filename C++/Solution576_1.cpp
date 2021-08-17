#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution576_1 {
public:
    const int MOD = 1e9 + 7;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][i][j] = 1;
        ll ans = 0;
        for(int step = 0; step < N; step++){
            for(int row = 0; row < m; row++){
                for(int col = 0; col < n; col++){
                    if(dp[step][row][col] > 0){
                        for(int k = 0; k < 4; k++){
                            int nextX = row + dir[k][0], nextY = col + dir[k][1];
                            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n){
                                 ans += dp[step][row][col];
                                 ans %= MOD;
                            }
                            else{
                                dp[step + 1][nextX][nextY] += dp[step][row][col];
                                dp[step + 1][nextX][nextY] %= MOD;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};