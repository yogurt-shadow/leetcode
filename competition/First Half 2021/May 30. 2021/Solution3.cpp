#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution3
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        priority_queue<pii, vector<pii>, greater<pii>> busy, idle;
        int time = 0;
        vector<int> ans(tasks.size(), 0);
        for (int i = 0; i < servers.size(); i++)
        {
            idle.push({servers[i], i});
        }
        int index = 0;
        while (index < tasks.size())
        {
            time = max(time, index);
            while (!busy.empty() && busy.top().first <= time)
            {
                auto cur = busy.top();
                busy.pop();
                idle.push({servers[cur.second], cur.second});
            }
            if (idle.empty())
            {
                time = busy.top().first;
            }
            else
            {
                auto cur = idle.top();
                ans[index++] = cur.second;
                idle.pop();
                busy.push({time + tasks[index - 1], cur.second});
            }
        }
        return ans;
    }
};

int main(){
   
    return 0;
}