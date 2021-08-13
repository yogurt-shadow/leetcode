#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution300 {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;
        for (auto ele : nums)
        {
            if (ans.size() == 0 || ele > ans.back())
            {
                ans.push_back(ele);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();
                ans[index] = ele;
            }
        }
        return ans.size();
    }
};