#include<iostream>
#include<vector>

using namespace std;

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1){
            return nums[0] == target ? 0 : -1;
        }
        int left = 0, right = size - 1;
        if(nums[left] == target){
            return 0;
        }
        if(nums[right] == target){
            return size - 1;
        }
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > nums[left]){
                if(target > nums[left] && target < nums[mid]){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            else{
                if(target > nums[mid] && target < nums[right]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
        }
        return -1;
    }
};


int main(){
    Solution33 s;
    vector<int> test = {4, 5, 6, 7, 8};
    cout << s.search(test, 5);
    return 0;
}