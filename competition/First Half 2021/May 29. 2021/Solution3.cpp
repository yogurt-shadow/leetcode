#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;

class Solution3 {
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int len = 0; i + 2 * len < n && j - len >= 0 && j + len < m; len++)
                {
                    int sum = grid[i][j];
                    if (len > 0)
                    {
                        for (int cur = 1; cur <= len; cur++)
                        {
                            sum += grid[i + cur][j + cur] + grid[i + cur][j - cur];
                        }
                        int endi = i + 2 * len;
                        int endj = j;
                        sum += grid[endi][endj];
                        for (int cur = 1; cur < len; cur++)
                        {
                            sum += grid[endi - cur][endj + cur] + grid[endi - cur][endj - cur];
                        }
                    }
                    pq.push(sum);
                }
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 3)
        {
            int cur = pq.top();
            pq.pop();
            if (ans.size() == 0 || ans[ans.size() - 1] != cur)
            {
                ans.push_back(cur);
            }
        }
        return ans;
    }
};

int main(){

    
    return 0;
}