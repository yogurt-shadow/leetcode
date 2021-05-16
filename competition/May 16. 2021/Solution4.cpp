#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<ll>> vec(1001, vector<ll>(1001, 0));

class Solution4
{
public:
    int dp(int n, int k)
    {
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= min(i, k); j++)
            {
                vec[i][j] = vec[i - 1][j - 1] + (ll)(i - 1) * vec[i - 1][j];
                vec[i][j] %= MOD;
            }
        }
        return vec[n][k];
    }

    int rearrangeSticks(int n, int k)
    {
        vec[1][1] = 1;
        return dp(n, k);
    }
};