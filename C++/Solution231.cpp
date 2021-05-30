#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution231 {
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
        {
            return false;
        }
        n = abs(n);
        int ans = 0;
        for (int i = 0; i <= 31; i++)
        {
            ans += ((1 << i) & n) ? 1 : 0;
        }
        return ans == 1;
    }
};