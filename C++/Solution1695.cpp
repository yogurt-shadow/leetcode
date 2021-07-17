#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_set>

using namespace std;

class Solution1695 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int left = 0;
        int sum = 0;
        unordered_set<int> s;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(s.count(nums[right]) > 0){
                s.erase(nums[left]);
                sum -= nums[left];
                left ++;
            }
            s.insert(nums[right]);
            ans = max(ans, sum);
        }
        return ans;
    }
};