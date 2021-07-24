#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution3 {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        vector<int> endpoints;
        for (auto &segment : segments)
        {
            endpoints.emplace_back(segment[0]);
            endpoints.emplace_back(segment[1]);
        }
        sort(endpoints.begin(), endpoints.end());
        endpoints.resize(unique(endpoints.begin(), endpoints.end()) - endpoints.begin());
        map<int, int> mp;
        int idx = 1;
        for (int endpoint : endpoints)
            mp[endpoint] = idx++;

        vector<long long> diff(idx);
        for (auto &segment : segments)
        {
            int l = segment[0], r = segment[1], c = segment[2];
            diff[mp[l]] += c, diff[mp[r]] -= c;
        }

        vector<vector<long long>> ans;
        long long now = 0;
        for (int i = 1; i < idx; ++i)
        {
            now += diff[i];
            if (now != 0)
                ans.push_back({endpoints[i - 1], endpoints[i], now});
        }

        return ans;
    }
};

int main(){

    return 0;
}