#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;


class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        int x = -prices[0] - fee, y = INT_MIN, z = 0;
        for(int i = 1; i < size; i++){
            int curx = z - prices[i] - fee;
            int cury = max(x, y);
            int curz = max(z, max(x, y) + prices[i]);
            x = curx, y = cury, z = curz;
        }
        return z;
    }
};