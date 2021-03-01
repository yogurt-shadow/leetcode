#include<iostream>
#include<vector>

#include<deque>

using namespace std;

class Solution45 {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int maxlen = 0;
        int step = 0;
        int cur = 0;
        while(maxlen < size - 1){
            int next = maxlen;
            while(cur <= maxlen){
                next = max(next, cur + nums[cur]);
                cur++;
            }
            maxlen = next;
            step++;
        }
        return step;
    }
};