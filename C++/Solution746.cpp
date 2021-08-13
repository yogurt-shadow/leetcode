#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size + 1);
        for(int i = 2; i <= size; i++){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};