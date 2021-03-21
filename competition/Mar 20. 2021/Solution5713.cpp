#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution5713 {
public:
    int count(int n){
        int ans = 0;
        while(n > 0){
            n = n&(n-1);
            ans++;
        }
        return ans;
    }

    int gcd(int x, int y){
        if(x == y){
            return x;
        }
        return gcd(min(x, y), max(x, y) - min(x, y));
    }
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1<<n,0);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                dp[(1<<i)|(1<<j)] = gcd(nums[i],nums[j]);
            }
        }
        
        for(int i = 1; i < (1<<n); ++i){
            if(count(i)%2) continue;
            for(int j = i; j != 0; j = (j-1)&i){
                if(count(i) - count(j) == 2){
                    dp[i] = max(dp[i],dp[j] + (count(i)/2)*dp[i^j]);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
