#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

class Solution494 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        vii dp(size + 1, vi(2001));
        dp[0][1000] = 1;
        for(int i = 1; i <= size; i++){
            for(int j = -1000; j <= 1000; j++){
                if(j - nums[i - 1] >= -1000 && j - nums[i - 1] <= 1000){
                    dp[i][j + 1000] += dp[i - 1][j + 1000 - nums[i - 1]];
                }
                if(j + nums[i - 1] >= -1000 && j + nums[i - 1] <= 1000){
                    dp[i][j + 1000] += dp[i - 1][j + 1000 + nums[i - 1]];
                }
            }
        }
        return dp[size][target + 1000];
    }
};