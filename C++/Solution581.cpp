#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution581 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return 0;
        }
        vector<int> copy(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = size - 1;
        while(left < size && nums[left] == copy[left]){
            left++;
        }
        if(left == size){
            return 0;
        }
        while(right >= 0 && nums[right] == copy[right]){
            right--;
        }
        return right - left + 1;
    }
};

int main(){
    vector<int> test = {2, 2};
    Solution581 s;
    cout << s.findUnsortedSubarray(test);
    return 0;
}