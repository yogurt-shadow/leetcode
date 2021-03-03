#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        dp[0] = 1;
        for(int i = 1; i < size; i++){
            int mm = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    mm = max(mm, dp[j]);
                }
            }
            dp[i] = mm + 1;
        }
        int res = 0;
        for(int i = 0; i < size; i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};