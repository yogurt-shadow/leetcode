#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;


class Solution80 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        int slow = 1;
        int fast = 2;
        while(fast < nums.size()){
            if(nums[slow - 1] != nums[fast]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};