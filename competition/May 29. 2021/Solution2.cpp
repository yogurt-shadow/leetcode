#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

class Solution2 {
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int cur = nums[i] + nums[nums.size() - 1 - i];
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main(){

    
    return 0;
}