#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution1
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int size = nums.size();
        int x = pow(2, size);
        int ans = 0;
        for (int k = 0; k < x; k++)
        {
            int cur = 0;
            for (int j = size - 1; j >= 0; j--)
            {
                if ((1 << j) & k)
                {
                    cur = cur ^ nums[j];
                }
            }
            ans += cur;
        }
        return ans;
    }
};