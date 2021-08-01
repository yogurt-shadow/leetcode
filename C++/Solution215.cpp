#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return -1;
        }
        vector<int> small, large;
        int pivot = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= pivot){
                large.push_back(nums[i]);
            }
            else{
                small.push_back(nums[i]);
            }
        }
        if(large.size() + 1 == k){
            return pivot;
        }
        if(large.size() + 1 > k){
            return findKthLargest(large, k);
        }
        return findKthLargest(small, k - large.size() - 1);
    }
};