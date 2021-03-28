#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution330 {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        long long cur = 0;
        int res = 0;
        int index = 0;
        int size = nums.size();
        while(cur < n){
            if(index >= size){
                cur += cur + 1;
                res++;
            }
            else{
                if(nums[index] <= cur + 1){
                    cur += nums[index];
                    index++;
                }
                else{
                    cur += cur + 1;
                    res++;
                }
            }
        }
        return res;
    }
};