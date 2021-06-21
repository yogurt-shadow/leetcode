#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution1049 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int size = stones.size();
        int sum = 0;
        for(auto ele: stones){
            sum += ele;
        }
        vector<vector<int>> dp(size + 1, vector<int>(sum / 2 + 1));
        dp[0][0] = 1;
        for(int i = 0; i < size; i++){
            for(int j = 0; j <= sum / 2; j++){
                dp[i + 1][j] = dp[i][j];
                if(j >= stones[i]){
                    dp[i + 1][j] |= dp[i][j - stones[i]];
                }
            }
        }
        for(int i = sum / 2; i >= 0; i--){
            if(dp[size][i]){
                return sum - 2 * i;
            }
        }
        return 0;
    }
};