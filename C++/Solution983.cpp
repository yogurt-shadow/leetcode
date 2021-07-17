#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution983 {
public:
    int dp[366] = {0};
    vector<int> costs;
    unordered_set<int> tra;

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        this -> costs = costs;
        for(int day: days){
            tra.insert(day);
        }
        return dfs(1);
    }

    int dfs(int x){
        if(x > 365){
            return 0;
        }
        if(dp[x]){
            return dp[x];
        }
        if(tra.count(x)){
            dp[x] = dfs(x + 1) + costs[0];
            dp[x] = min(dp[x], dfs(x + 7) + costs[1]);
            dp[x] = min(dp[x], dfs(x + 30) + costs[2]);
            return dp[x];
        }
        return dp[x] = dfs(x + 1);
    }
};