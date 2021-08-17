#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution931 {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp.back() = matrix.back();
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                for(int dep = -1; dep <= 1; dep++){
                    if(j + dep >= 0 && j + dep < m){
                        dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + dep]);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto ele: dp.front()){
            ans = min(ans, ele);
        }
        return ans;
    }
};