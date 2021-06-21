#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution322 {
public:
    vector<int> dp;
    vector<int> coins;

    int dfs(int x){
        if(x == 0){
            return 0;
        }
        if(dp[x]){
            return dp[x];
        }
        if(x < coins[0]){
            dp[x] = -1;
            return -1;
        }
        int index = 0;
        bool cannot = true;
        dp[x] = INT_MAX;
        while(index < coins.size() && coins[index] <= x){
            if(dfs(x - coins[index]) == -1){
                continue;
            }
            cannot = false;
            dp[x] = min(dp[x], 1 + dfs(x - coins[index]));
        }
        if(cannot){
            dp[x] = -1;
            return -1;
        }
        return dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        this -> coins = coins;
        dp.resize(amount + 1);
        return dfs(amount);
    }
};