#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution740 {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = -1;
        int size = nums.size();
        for(auto ele: nums){
            maxValue = max(ele, maxValue);
        }
        sum.resize(maxValue + 1);
        for(int i = 0; i < size; i++){
            sum[nums[i]] += nums[i];
        }
        return rob2(sum);
    }

private:
    vector<int> sum;

    int rob2(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        if (size == 1)
            return nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[size - 1];
    }
};