#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

class Solution325 {
public:
    int maxSubArrayLen(vector<int> &nums, int k){
        int size = nums.size();
        int ans = 0;
        unordered_map<int, int> pre; // pre stores [preSum, index] which index is the smallest whose sum is preSum
        pre[0] = 0;
        int cur = 0;
        for (int i = 0; i < size; i++){
            cur += nums[i];
            if (pre.count(cur) == 0){
                pre[cur] = i + 1;
            }
            if (pre.count(cur - k)){
                ans = max(ans, i + 1 - pre[cur - k]);
            }
        }
        return ans;
    }
};