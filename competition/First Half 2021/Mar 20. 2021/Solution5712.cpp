#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution5712 {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int cur = 0;
        for(auto ele: coins){
            if(ele > cur + 1){
                return cur + 1;
            }
            cur += ele;
        }
        return cur + 1;
    }
};