#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution518 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(auto ele: coins){
            for(int i = ele; i <= amount; i++){
                dp[i] += dp[i - ele];
            }
        }
        return dp[amount];
    }
};