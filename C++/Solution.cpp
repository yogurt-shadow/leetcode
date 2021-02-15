#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int mincost(vector<int>& cost){
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

int main(){
    
     vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
     Solution solution;
     cout << solution.mincost(cost)<< endl;
}