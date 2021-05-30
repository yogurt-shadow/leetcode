#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

class Solution3 {
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq, pq2;
        int n = servers.size();
        vector<int> tm(n);
        for (int i = 0; i < n; ++i)
            pq2.emplace(servers[i], i);

        int q = tasks.size();
        int now = 0;
        vector<int> ans(q);
        for (int i = 0; i < q; ++i)
        {
            now = max(now, i);
            while (!pq.empty() && pq.top().first <= now)
            {
                pq2.emplace(servers[pq.top().second], pq.top().second);
                pq.pop();
            }
            if (pq2.empty())
            {
                int t = pq.top().first;
                while (!pq.empty() && pq.top().first == t)
                {
                    pq2.emplace(servers[pq.top().second], pq.top().second);
                    pq.pop();
                }
                now = t;
            }
            auto [w, idx] = pq2.top();
            pq2.pop();
            pq.emplace(now + tasks[i], idx);
            ans[i] = idx;
            tm[idx] = now + tasks[i];
        }

        return ans;
    }
};

int main(){
   
    return 0;
}