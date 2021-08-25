#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution552 {
public:
    const int MOD = 1e9 + 7;

    int checkRecord(int n) {
        viii dp(n + 1, vii(2, vi(3, 0)));  // len, num of A, last num of L
        dp[0][0][0] = 1;
        for(int len = 1; len <= n; len++){
            // L
            for(int numA = 0; numA < 2; numA++){
                for(int lastL = 1; lastL < 3; lastL++){
                    dp[len][numA][lastL] = (dp[len][numA][lastL] + dp[len - 1][numA][lastL - 1]) % MOD;
                }
            }
            // P
            for(int numA = 0; numA < 2; numA++){
                for(int lastL = 0; lastL < 3; lastL++){
                    dp[len][numA][0] = (dp[len][numA][0] + dp[len - 1][numA][lastL]) % MOD;
                }
            }
            // A
            for(int lastL = 0; lastL < 3; lastL++){
                dp[len][1][0] = (dp[len][1][0] + dp[len - 1][0][lastL]) % MOD;
            }
        }
        int ans = 0;
        for(int numA = 0; numA < 2; numA++){
            for(int lastL = 0; lastL < 3; lastL++){
                ans += dp[n][numA][lastL];
                ans %= MOD;
            }
        }
        return ans;
    }
};