#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution413 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        vector<vector<int>> dp(size, vector<int>(size, INT_MAX));
        for(int i = 0; i + 2 < size; i++){
            int x = nums[i + 1] - nums[i];
            int y = nums[i + 2] - nums[i + 1];
            if(x == y){
                ans ++;
                dp[i][i + 2] = x;
            }
            else{
                dp[i][i + 2] = INT_MAX;
            }
        }
        for(int i = 0; i < size; i++){
            for(int j = i + 3; j < size; j++){
                if(dp[i][j - 1] != INT_MAX && nums[j] - nums[j - 1] == dp[i][j - 1]){
                    ans ++;
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return ans;
    }
};