#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution2 {
public:
    int reductionOperations(vector<int> &nums)
    {
        int cc = 0;
        unordered_map<int, int> mp;
        for (auto ele : nums)
        {
            mp[ele]++;
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ans.size() == 0 || ans[ans.size() - 1] < nums[i])
            {
                ans.push_back(nums[i]);
            }
        }
        int last = ans[ans.size() - 1];
        for (int i = ans.size() - 2; i >= 0; i--)
        {
            cc += mp[last];
            mp[ans[i]] += mp[last];
            last = ans[i];
        }
        return cc;
    }
};