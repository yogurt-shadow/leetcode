#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Offer53_1 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        int index1 = upper(nums, target), index2 = lower(nums, target);
        //cout << index1 << index2 << endl;
        if(index1 == -1 || index2 == -1){
            return 0;
        }
        return index1 - index2 + 1;
    }

    int upper(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        if(nums[left] > target){
            return -1;
        }
        if(nums[right] < target){
            return -1;
        }
        if(nums[right] == target){
            return right;
        }
        while(right - left > 1){
            //cout << left << right << endl;
            int mid = (left + right) / 2;
            if(nums[mid] <= target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }

    int lower(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        if(nums[left] > target){
            return -1;
        }
        if(nums[right] < target){
            return -1;
        }
        if(nums[left] == target){
            return left;
        }
        while(right - left > 1){
            //cout << left << right << endl;
            int mid = (left + right) / 2;
            if(nums[mid] >= target){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return nums[right] == target ? right : -1;
    }
};