#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

class Solution16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int result = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int index1 = 0; index1 < size; index1++){
            if(index1 > 0 && nums[index1] == nums[index1 - 1]){
                continue;
            }
            int tar = target - nums[index1];
            int index2 = index1 + 1, index3 = size - 1;
            while(index3 > index2){
                int sum = nums[index2] + nums[index3];
                if(sum == tar){
                    return target;
                }
                if(result >= abs(sum - tar)){
                    result = abs(sum - tar);
                    ans = sum + nums[index1];
                }
                if(sum > tar){
                    index3--;
                }
                else{
                    index2++;
                }
            }
        }
        return ans;
    }
};