#include<iostream>
#include<vector>

using namespace std;

class Solution1480 {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        result[0] = nums[0];
        for(int i = 1; i < size; i++){
            result[i] = result[i - 1] + nums[i];
        }
        return result;
    }
};