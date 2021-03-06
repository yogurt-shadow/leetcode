#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution60 {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        while(k > 1){
            nextPermutation(nums);
            k--;
        }
        string str = "";
        for(int i = 0; i < n; i++){
            str +=  nums[i] + '0';
        }
        return str;
    }
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        bool order = true;
        int index1;
        for(int i = size - 1; i >= 1; i--){
            if(nums[i - 1] < nums[i]){
                order = false;
                index1 = i - 1;
                break;
            }
        }
        if(order){
            reverse(nums, 0, size - 1);
            return;
        }
        int index2, mm = INT_MAX;
        for(int i = size - 1; i > index1; i--){
            if(nums[i] > nums[index1]){
                if(nums[i] < mm){
                    mm = nums[i];
                    index2 = i;
                }
            }
        }
        int copy = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = copy;
        reverse(nums, index1 + 1, size - 1);
    }

    void reverse(vector<int>& nums, int start, int end){
        int right = end, left = start;
        while(right > left){
            int copy = nums[left];
            nums[left] = nums[right];
            nums[right] = copy;
            left++;
            right--;
        }
    }
};