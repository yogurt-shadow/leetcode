#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution1
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int mm = 0;
        int year = 0;
        int ans = 0;
        int j = 0;
        sort(logs.begin(), logs.end());
        vector<int> death;
        for (auto ele : logs)
        {
            death.push_back(ele[1]);
        }
        sort(death.begin(), death.end());
        for (int i = 0; i < logs.size(); i++)
        {
            int cur = logs[i][0];
            ans++;
            while (death[j] <= cur)
            {
                j++;
                ans--;
            }
            if (ans > mm)
            {
                mm = ans;
                year = logs[i][0];
            }
        }
        return year;
    }
};