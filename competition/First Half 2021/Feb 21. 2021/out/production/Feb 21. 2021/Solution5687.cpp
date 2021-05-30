#include<iostream>
#include<vector>

using namespace std;

class Solution5687 {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 0;
        for(int left = 1; left <= m; left++){
            dp[left][0] = dp[left - 1][0] + nums[left - 1] * multipliers[left - 1];
        }
        for(int right = 1; right <= m; right++){
            dp[0][right] = dp[0][right - 1] + nums[n - right] * multipliers[right - 1];
        }
        for(int left = 1; left <= m; left++){
            for(int right = 1; left + right <= m; right++){
                int mul = multipliers[left + right - 1];
                dp[left][right] = max(dp[left - 1][right] + mul * nums[left - 1], dp[left][right - 1] + mul * nums[n - right]);
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i <= m; i++){
            ans = max(ans, dp[i][m - i]);
        }
        return ans;
    }
};