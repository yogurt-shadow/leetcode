#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;


class Solution5704 {
public:
    int maximumScore(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> left(size), right(size);
        stack<int> stk, stk2;
        for(int i = 0; i < size; i++){
            while(!stk.empty() && nums[stk.top()] >= nums[i]){
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for(int i = size - 1; i >= 0; i--){
            while(!stk2.empty() && nums[stk2.top()] >= nums[i]){
                stk2.pop();
            }
            right[i] = stk2.empty() ? size : stk2.top();
            stk2.push(i);
        }
        int res = 0;
        for(int i = 0; i < size; i++){
            if(left[i] + 1 <= k && right[i] - 1 >= k){
                res = max(res, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return res;
    }
};