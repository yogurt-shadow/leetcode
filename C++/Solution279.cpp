#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution279 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++){
            int ans = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                int cur = 1 + dp[i - j * j];
                ans = min(ans, cur);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};