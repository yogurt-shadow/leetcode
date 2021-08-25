#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

class Solution487 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int num = 0;
        int ans = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                num ++;
            }
            while(num > 1){
                if(nums[left] == 0){
                    num--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};