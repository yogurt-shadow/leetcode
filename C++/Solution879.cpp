#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution879 {
public:
    const int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size();
        viii dp(size + 1, vii(n + 1, vi(minProfit + 1)));
        dp[0][0][0] = 1;
        for(int i = 1; i <= size; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= minProfit; k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(group[i - 1] <= j){
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(k - profit[i - 1], 0)];
                    }
                    dp[i][j][k] %= MOD;
                }
            }
        }
        ll sum = 0;
        for(int i = 0; i <= n; i++){
            sum += dp[size][i][minProfit];
            sum %= MOD;
        }
        return sum;
    }
};