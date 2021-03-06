#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution81 {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if(nums[left] == target || nums[right] == target){
            return true;
        }
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[left]){
                left++;
                continue;
            }
            if(nums[mid] > nums[left]){
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};