#include<iostream>
#include<vector>

using namespace std;

class Solution1480 {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};