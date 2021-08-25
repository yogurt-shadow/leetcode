#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;


class Solution787 {
public:
    const int MAX = 0x3f3f3f3f;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, MAX));
        dp[0][src] = 0;
        for(int time = 1; time <= k + 1; time++){
            for(auto edge: flights){
                dp[time][edge[1]] = min(dp[time][edge[1]], dp[time - 1][edge[0]] + edge[2]);
            }
        }
        int ans = MAX;
        for(int time = 0; time <= k + 1; time++){
            ans = min(ans, dp[time][dst]);
        }
        return ans == MAX ? -1 : ans;
    }
};