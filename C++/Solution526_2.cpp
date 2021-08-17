#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution526_2 {
public:
    vector<int> dp;

    int countArrangement(int n) {
        dp.resize(1 << n);
        dp[0] = 1;
        for(int mask = 1; mask < (1 << n); mask++){
            int cur = 0;
            int num = numberOne(mask);
            for(int k = 0; k < n; k++){
                if((mask & (1 << k)) == 0){
                    continue;
                }
                int digit = k + 1;
                if(digit % num == 0 || num % digit == 0){
                    cur += dp[mask - (1 << k)];
                }
            }
            dp[mask] = cur;
        }
        return dp[(1 << n) - 1];
    }

private:
    int numberOne(int x){
        int ans = 0;
        while(x){
            ans ++;
            x = x & (x - 1);
        }
        return ans;
    }
};