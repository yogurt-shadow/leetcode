#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

typedef long long ll;

class Solution3{
public:
    const int MOD = 1000000000 + 7;
    int countNicePairs(vector<int>& nums) {
        int size = nums.size();
        vector<ll> store(size);
        for(int i = 0; i < size; i++){
            store[i] = nums[i] - rev(nums[i]);
        }
        sort(store.begin(), store.end());
        ll res = 0;
        ll cur = 1;
        for(int i = 1; i < store.size(); i++){
            if(store[i] == store[i - 1]){
                cur++;
            }
            else{
                ll value = (cur - 1) * cur;
                res += (value / 2) % MOD;
                res = res % MOD;
                cur = 1;
            }
        }
        ll value = (cur - 1) * cur;
        res += (value / 2) % MOD;
        res %= MOD;
        return res;
    }

    ll rev(int x){
        ll res = 0;
        while(x){
            res = 10 * res + x % 10;
            x = x / 10;
        }
        return res;
    }
};