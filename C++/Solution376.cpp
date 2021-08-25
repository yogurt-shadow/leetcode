#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution376 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(2)); // up down
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < size; i++){
            if(nums[i] > nums[i - 1]){
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
            }
            else{
                dp[i][0] = dp[i - 1][0];
            }
            if(nums[i] < nums[i - 1]){
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
            }
            else{
                dp[i][1] = dp[i - 1][1];
            }
        }
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};