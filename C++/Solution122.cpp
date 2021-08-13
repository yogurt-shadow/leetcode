#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int x = -prices[0], y = 0;
        for(int i = 1; i < size; i++){
            int curx = max(x, y - prices[i]);
            int cury = max(y, x + prices[i]);
            x = curx;
            y = cury;
        }
        return y;
    }
};