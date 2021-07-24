#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
typedef long long ll;

class Solution5815 {
public:
    long long maxPoints(vector<vector<int>> &points){
        int n = points.size(), m = points[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m));
        for(int i = 0; i < m; i++){
            dp[0][i] = points[0][i];
        }
        for(int i = 1; i < n; i++){
            ll cur = dp[i - 1][0];
            for(int j = 0; j < m; j++){
                cur = max(cur, dp[i - 1][j] + j);
                dp[i][j] = cur + points[i][j] - j;
            }
            cur = dp[i - 1][m - 1] - (m - 1);
            for(int j = m - 1; j >= 0; j--){
                cur = max(cur, dp[i - 1][j] - j);
                dp[i][j] = max(dp[i][j], points[i][j] + cur + j);
            }
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};