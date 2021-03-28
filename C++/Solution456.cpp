#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution456 {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return false;
        }
        vector<int> dp(size);
        dp[0] = nums[0];
        for(int i = 1; i < size; i++){
            dp[i] = min(dp[i - 1], nums[i]);
        }
        stack<int> stk;
        for(int j = size - 1; j >= 0; j--){
            if(nums[j] == dp[j]){
                continue;
            }
            while(!stk.empty() && stk.top() <= dp[j]){
                stk.pop();
            }
            if(!stk.empty() && stk.top() < nums[j]){
                return true;
            }
            stk.push(nums[j]);
        }
        return false;
    }
};