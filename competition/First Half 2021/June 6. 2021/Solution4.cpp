#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;

class Solution4 {
public:
    const int MOD = 1e9 + 7;

    int binarySearch(vector<int> &arr, int target)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }

    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        sort(packages.begin(), packages.end());
        vector<ll> pre(packages.size() + 1, 0);
        for (int i = 1; i <= packages.size(); i++)
        {
            pre[i] = pre[i - 1] + packages[i - 1];
        }
        ll ans = LLONG_MAX;
        bool cannot = true;
        for (int i = 0; i < boxes.size(); i++)
        {
            ll cur = 0;
            sort(boxes[i].begin(), boxes[i].end());
            if (boxes[i][boxes[i].size() - 1] < packages[packages.size() - 1])
            {
                continue;
            }
            cannot = false;
            int index = 0;
            for (int j = 0; j < boxes[i].size(); j++)
            {
                if (boxes[i][j] < packages[index])
                {
                    continue;
                }
                int r = packages.size() - 1;
                if (packages[r] <= boxes[i][j])
                {
                    cur += boxes[i][j] * (packages.size() - index) - (pre[packages.size()] - pre[index]);
                    break;
                }
                int x = binarySearch(packages, boxes[i][j]);
                cur += (ll)boxes[i][j] * (x - index + 1) - (pre[x + 1] - pre[index]);
                index = x + 1;
            }
            ans = min(ans, cur);
        }
        if (cannot)
        {
            return -1;
        }
        return ans % MOD;
    }
};