#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution525 {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int counter = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                counter ++;
            }
            else{
                counter --;
            }
            if(mp.count(counter)){
                ans = max(ans, i - mp[counter]);
            }
            else{
                mp[counter] = i;
            }
        }
        return ans;
    }
};