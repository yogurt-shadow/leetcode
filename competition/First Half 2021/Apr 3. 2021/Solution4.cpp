#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

typedef long long ll;

class Solution4{
    unordered_map<ll, int> mp;
    int batchSize;
    int dfs(int cur, ll state){
        if(mp.count(state)){
            return mp[state];
        }
        if(!state){
            mp[state] = 0;
            return 0;
        }
        int res = 0;
        for(int i = 1; i < batchSize; i++){
            if((state >> (i * 5)) % 32){
                int temp = dfs((cur + i) % batchSize, state -(1ll<<(i*5)));
                res = max(res, cur ? temp : temp + 1);
            }
        }
        mp[state] = res;
        return res;
    }

public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        this -> batchSize = batchSize;
        ll state = 0;
        int mod0 = 0;
        for(auto ele: groups){
            ele = ele % batchSize;
            if(!ele){
                mod0++;
            }
            else{
                state += 1ll<<(ele * 5);
            }
        }
        return mod0 + dfs(0, state);
    }

};