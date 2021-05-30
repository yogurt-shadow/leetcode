#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;

class Solution4
{
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size();
        int sum = 0;
        for (int di : dist)
            sum += di;
        if (1LL * speed * hoursBefore < sum)
            return -1;

        auto inf = make_pair(INT_MAX, INT_MAX);
        vector<pair<int, int>> f(n + 1, inf);
        f[0] = make_pair(0, 0);
        for (int di : dist)
        {
            vector<pair<int, int>> nf(n + 1, inf);
            for (int i = 0; i <= n; ++i)
            {
                if (f[i] < inf)
                {
                    auto [t, d] = f[i];
                    nf[i] = min(nf[i], make_pair(t + (d + di - 1) / speed + 1, 0));
                    if (i + 1 <= n)
                        nf[i + 1] = min(nf[i + 1], make_pair(t + (d + di) / speed, (d + di) % speed));
                }
            }
            f = move(nf);
        }
        auto target = make_pair(hoursBefore, 0);
        for (int i = 0; i <= n; ++i)
            if (f[i] <= target)
                return i;

        return -1;
    }
};