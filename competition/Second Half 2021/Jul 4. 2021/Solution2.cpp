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

class Solution2 {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int size = speed.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            if (dist[i] % speed[i] == 0)
            {
                ans[i] = dist[i] / speed[i];
            }
            else
            {
                ans[i] = dist[i] / speed[i] + 1;
            }
        }
        int index = 0;
        sort(ans.begin(), ans.end());
        while (index < size && index < ans[index])
        {
            index++;
        }
        return index;
    }
};

int main()
{

    return 0;
}