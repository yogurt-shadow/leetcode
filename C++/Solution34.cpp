#include<iostream>
#include<vector>

using namespace std;

class Solution34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int size = nums.size();
        if(size == 0){
            return vector<int>{-1, -1};
        }
        int right = size - 1;
        vector<int> result(2);
        if(target == nums[left]){
            int index = 0;
            while(index < size && nums[index] == target){
                index++;
            }
            result[0] = 0; result[1] = index - 1;
            return result;
        }
        if(target == nums[right]){
            int index = size - 1;
            while(index >= 0 && nums[index] == target){
                index--;
            }
            result[0] = index + 1; result[1] = right;
            return result;
        }
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(target == nums[mid]){
                int index1 = mid, index2 = mid;
                while(index1 >= 0 && nums[index1] == target){
                    index1--;
                }
                while(index2 < size && nums[index2] == target){
                    index2++;
                }
                result[0] = index1 + 1; result[1] = index2 - 1;
                return result;
            }
            else if(target > nums[mid]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        result[0] = -1; result[1] = -1;
        return result;
    }
};