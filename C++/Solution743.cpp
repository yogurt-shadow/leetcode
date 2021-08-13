#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;

#define MAX 0x3f3f3f3f

class Solution743 {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        dist.resize(n + 1, MAX);
        dist[k] = 0;
        visited.resize(n + 1);
        for (auto &ele : times)
        {
            mp[ele[0]][ele[1]] = ele[2];
        }
        pq.push({0, k});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (visited[cur.second])
            {
                continue;
            }
            //cout << cur.second << endl;
            visited[cur.second] = 1;
            for (auto neighbor : mp[cur.second])
            {
                //cout << neighbor.first << endl;
                dist[neighbor.first] = min(dist[neighbor.first], neighbor.second + dist[cur.second]);
                pq.push({dist[neighbor.first], neighbor.first});
            }
        }
        int ans = 0;
        for (int i = 1; i < dist.size(); i++)
        {
            if (dist[i] == MAX)
            {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }

private:
    vector<int> visited;
    vector<int> dist;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    unordered_map<int, unordered_map<int, int>> mp;
};

int main(){
    cout << MAX << endl;
    return 0;
}