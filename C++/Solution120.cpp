#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle.back().size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp.back() = triangle.back();
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                for(int dep = 0; dep <= 1; dep++){
                    if(dep >= 0 && dep < m){
                        dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i + 1][j + dep]);
                    }
                }
            }
        }
        return dp.front().front();
    }
};