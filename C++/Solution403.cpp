#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution403 {
public:
    unordered_map<int, int> mp;
    vector<unordered_map<int, int>> mem;

    bool dfs(vector<int>& stones, int pos, int last){
        if(pos == stones.size() - 1){
            return true;
        }
        if(mem[pos].count(last)){
            return mem[pos][last]; 
        }
        for(int cur = last - 1; cur <= last + 1; cur++){
            if(cur > 0){
                int st = stones[pos] + cur;
                if(mp.count(st)){
                    if(dfs(stones, mp[st], cur)){
                        mem[pos][last] = 1;
                        return true;
                    }
                }  
            }
        }
        mem[pos][last] = 0;
        return false;
    }

    bool canCross(vector<int>& stones) {
        int size = stones.size();
        mem.resize(size);
        for(int i = 0; i < size; i++){
            mp[stones[i]] = i;
        }
        return dfs(stones, 0, 0);
    }
};