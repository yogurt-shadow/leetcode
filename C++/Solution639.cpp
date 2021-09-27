#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution639 {
public:
    const int MOD = 1e9 + 7;

    int numDecodings(string s) {
        vector<ll> dp(s.length() + 1);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); i++){
            if(s[i - 1] == '0'){
                if(i - 2 >= 0 && s[i - 2] > '0' && s[i - 2] <= '2'){
                    dp[i] += dp[i - 2];
                    dp[i] %= MOD;
                }
                if(i - 2 >= 0 && s[i - 2] == '*'){
                    dp[i] += dp[i - 2] * 2;
                    dp[i] %= MOD;
                }
            }
            else if(s[i - 1] >= '1' && s[i - 1] <= '6'){
                dp[i] += dp[i - 1];
                dp[i] %= MOD;
                if(i - 2 >= 0 && s[i - 2] > '0' && s[i - 2] <= '2'){
                    dp[i] += dp[i - 2];
                    dp[i] %= MOD;
                }
                if(i - 2 >= 0 && s[i - 2] == '*'){
                    dp[i] += dp[i - 2] * 2;
                    dp[i] %= MOD;
                }
            }
            else if(s[i - 1] >= '7' && s[i - 1] <= '9'){
                dp[i] += dp[i - 1];
                dp[i] %= MOD;
                if(i - 2 >= 0 && s[i - 2] == '1'){
                    dp[i] += dp[i - 2];
                    dp[i] %= MOD;
                }
                if(i - 2 >= 0 && s[i - 2] == '*'){
                    dp[i] += dp[i - 2];
                    dp[i] %= MOD;
                }
            }
            else{
                dp[i] += dp[i - 1] * 9;
                dp[i] %= MOD;
                if(i - 2 >= 0 && s[i - 2] == '1'){
                    dp[i] += dp[i - 2] * 9;
                    dp[i] %= MOD;
                }
                if(i - 2 >= 0 && s[i - 2] == '2'){
                    dp[i] += dp[i - 2] * 6;
                    dp[i] %= MOD;
                }
                if(i - 2 >= 0 && s[i - 2] == '*'){
                    dp[i] += dp[i - 2] * 15;
                    dp[i] %= MOD;
                }
            }
        }
        return dp[s.length()];
    }
};