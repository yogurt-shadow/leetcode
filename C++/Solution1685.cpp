#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution1685 {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> pre(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            pre[i + 1] = pre[i] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            ans[i] = pre[nums.size()] - pre[i + 1] - nums[i] * (nums.size() - (i + 1));
            ans[i] += nums[i] * i - pre[i];
        }
        return ans;
    }
};