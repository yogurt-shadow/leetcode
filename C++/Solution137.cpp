#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution137 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto ele: nums){
            mp[ele] ++;
        }
        for(auto ele: mp){
            if(ele.second == 1){
                return ele.first;
            }
        }
        return 0;
    }
};