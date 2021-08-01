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
    vector<vector<int>> dp;
    int ans = 0;

    void dfs(int cur, vector<int> &occ, int cnt)
    {
        if (cur == occ.size())
        {
            ans = max(ans, cnt);
        }
        else
        {
            for (int i = 0; i < occ.size(); i++)
            {
                if (occ[i] == 0)
                {
                    occ[i] = 1;
                    dfs(cur + 1, occ, cnt + dp[cur][i]);
                    occ[i] = 0;
                }
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        dp.resize(students.size(), vector<int>(students.size()));
        for (int i = 0; i < students.size(); i++)
        {
            for (int j = 0; j < students.size(); j++)
            {
                auto &ele1 = students[i], ele2 = mentors[j];
                int cnt = 0;
                for (int k = 0; k < ele1.size(); k++)
                {
                    if (ele1[k] == ele2[k])
                    {
                        cnt++;
                    }
                }
                dp[i][j] = cnt;
            }
        }
        vector<int> occ(students.size());
        dfs(0, occ, 0);
        return ans;
    }
};

int main(){

    return 0;
}