#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution1561 {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size() / 3;
        int ans = 0;
        int step = 0;
        for(int i = 0; i + 1 < piles.size() && step <= n; i += 2, step++){
            ans += piles[i + 1];
        }
        return ans;
    }
};