#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution55 {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxlen = nums[0];
        int index = 0;
        while(index <= maxlen && maxlen < size - 1){
            maxlen = max(maxlen, index + nums[index]);
            index++;
        }
        return maxlen >= size - 1;
    }
};