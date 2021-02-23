#include<iostream>
#include<vector>

using namespace std;

class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1){
            return nums[0] >= target ? 0 : 1;
        }
        int left = 0, right = size - 1;
        if(target <= nums[left]){
            return 0;
        }
        if(target == nums[right]){
            return right;
        }
        if(target > nums[right]){
            return size;
        }
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(target == nums[mid]){
                return mid;
            }
            if(target > nums[mid]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};

int main(){
    Solution35 s;
    vector<int> test = {1, 3, 5, 6};
    cout << s.searchInsert(test, 2);
    return 0;
}