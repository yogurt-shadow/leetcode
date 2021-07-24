#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution5814 {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;
        int cur = 0;
        int index = 0;
        while(index < rungs.size()){
            if(rungs[index] - cur <= dist){
                cur = rungs[index];
                index++;
            }
            else{
                ans += (rungs[index] - cur - 1) / dist;
                cur = rungs[index];
            }
        }
        return ans;
    }
};