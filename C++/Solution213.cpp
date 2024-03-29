#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution213 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> copy1(nums.begin(), nums.end() - 1), copy2(nums.begin() + 1, nums.end());
        return max(rob2(copy1), rob2(copy2));
    }

    int rob2(vector<int> &nums){
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        if (size == 1) return nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[size - 1];
    }
};