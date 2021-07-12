#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution4 {
public:
    const int INF = 0x3f3f3f3f;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        vector<vector<int>> dp(maxTime + 1, vector<int>(passingFees.size(), INF));
        dp[0][0] = passingFees[0];
        for(int t = 1; t <= maxTime; t++){
            for(auto& edge: edges){
                int start = edge[0], end = edge[1], cost = edge[2];
                if(t >= cost){
                    dp[t][end] = min(dp[t][end], dp[t - cost][start] + passingFees[end]);
                    dp[t][start] = min(dp[t][start], dp[t - cost][end] + passingFees[start]);
                }
            }
        }
        int res = INF;
        for(int t = 1; t <= maxTime; t++){
            res = min(res, dp[t][passingFees.size() - 1]);
        }
        return res == INF ? -1 : res;
    }
};

int main(){
   
    
    return 0;
}