#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int cur = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > cur){
                cur = nums[i];
                sum += cur;
                res = max(res, sum);
            }
            else{
                cur = nums[i];
                sum = cur;
                res = max(res, sum);
            }
        }
        return res;
    }
};