#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_set>

using namespace std;

class Solution1567 {
public:
    int getMaxLen(vector<int> &nums)
    {
        vector<int> neg(nums.size()), pos(nums.size());
        int ans = 0;
        if (nums[0] > 0)
        {
            pos[0] = 1;
            ans = 1;
        }
        else if (nums[0] < 0)
        {
            neg[0] = 1;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                neg[i] = 0;
                pos[i] = 0;
            }
            else if (nums[i] > 0)
            {
                pos[i] = pos[i - 1] + 1;
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                ans = max(ans, pos[i]);
            }
            else
            {
                neg[i] = pos[i - 1] + 1;
                pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                ans = max(ans, pos[i]);
            }
        }
        return ans;
    }
};