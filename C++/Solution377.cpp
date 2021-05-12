#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto ele: nums){
                if(ele <= i && dp[i] < INT_MAX - dp[i - ele]){
                    dp[i] += dp[i - ele];
                }
            }
        }
        return dp[target];
    }
};