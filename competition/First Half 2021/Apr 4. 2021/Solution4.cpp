#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


class Solution4 {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int c = *max_element(nums.begin(), nums.end());
        vector<int> g(c + 1);
        
        for (int x: nums) {
            for (int y = 1; y * y <= x; ++y) {
                if (x % y == 0) {
                    if (!g[y]) {
                        g[y] = x;
                    }
                    else {
                        g[y] = gcd(g[y], x);
                    }
                    if (y * y != x) {
                        int z = x / y;
                        if (!g[z]) {
                            g[z] = x;
                        }
                        else {
                            g[z] = gcd(g[z], x);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= c; ++i) {
            if (g[i] == i) {
                ++ans;
            }
        }
        return ans;
    }
};