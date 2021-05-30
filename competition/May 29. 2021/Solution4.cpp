#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

class Solution4 {
public:
    int count(int x, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & x)
            {
                ans++;
            }
        }
        return ans;
    }

    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> f(1 << n, INT_MAX);
        f[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++)
        {
            for (int i = 0; i < n; i++)
            {
                if ((1 << i) & mask)
                {
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (nums1[count(mask, n) - 1] ^ nums2[i]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};

int main(){

    
    return 0;
}