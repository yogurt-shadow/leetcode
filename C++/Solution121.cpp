#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.back();
        int ans = 0;
        for(int i = prices.size() - 2; i >= 0; i--){
            ans = max(ans, m - prices[i]);
            m = max(m, prices[i]);
        }   
        return ans;
    }
};