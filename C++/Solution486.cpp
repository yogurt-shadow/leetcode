#include<iostream>
#include<vector>

using namespace std;

class Solution486 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = size % 2 == 1 ? nums[i] : -nums[i];
        }
        for(int j = 1; j < size; j++){
            for(int i = j - 1; i >= 0; i--){
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][size - 1] >= 0;
    }
};