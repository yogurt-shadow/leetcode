#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<string, int> psi;

class Solution692
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto ele : words)
        {
            mp[ele]++;
        }
        auto cmp = [](psi &a, psi &b) {
            if (a.second > b.second)
            {
                return false;
            }
            if (a.second == b.second)
            {
                return a.first > b.first;
            }
            return true;
        };

        priority_queue<psi, vector<psi>, decltype(cmp)> pq(cmp);
        for (auto ele : mp)
        {
            pq.push({ele.first, ele.second});
        }
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.first);
        }
        return ans;
    }
};