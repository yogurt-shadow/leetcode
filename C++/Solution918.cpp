#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution918 {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i < size; i++){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int minSubArray(vector<int>& nums){
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1; i < size; i++){
            dp[i] = min(nums[i], dp[i - 1] + nums[i]);
            ans = min(ans, dp[i]);
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int ans = maxSubArray(nums);
        int sum = 0;
        for(auto ele: nums){
            sum += ele;
        }
        vector<int> copy(nums.begin() + 1, nums.end() - 1);
        int x = minSubArray(copy);
        ans = max(ans, sum - x);
        return ans;
    }
};