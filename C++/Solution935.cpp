#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution935 {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    unordered_set<int> st[10] = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int knightDialer(int n) {
        dp.resize(10, vector<int>(n));
        int ans = 0;
        for(int i = 0; i < 10; i++){
            ans += dfs(i, n - 1);
            ans %= MOD;
        }
        return ans;
    }

    int dfs(int num, int step){
        if(step == 0){
            return 1;
        }
        if(dp[num][step]){
            return dp[num][step];
        }
        int ans = 0;
        for(auto ele: st[num]){
            ans += dfs(ele, step - 1);
            ans %= MOD;
        }
        return dp[num][step] = ans;
    }
};