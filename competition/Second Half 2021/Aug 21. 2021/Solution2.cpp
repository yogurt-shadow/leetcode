#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution2 {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        ll ans = 0;
        vector<ll> neg, pos;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] < 0)
                {
                    neg.push_back(matrix[i][j]);
                }
                else
                {
                    pos.push_back(matrix[i][j]);
                }
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        for (auto ele : pos)
        {
            ans += ele;
        }
        if (neg.size() % 2 == 0)
        {
            for (auto ele : neg)
            {
                ans -= ele;
            }
            return ans;
        }
        for (int i = 0; i < neg.size() - 1; i++)
        {
            ans -= neg[i];
        }
        if (pos.size() == 0)
        {
            return ans + neg.back();
        }
        return max(ans + neg.back(), ans - neg.back() - 2 * pos[0]);
    }
};

int main(){
    Solution2 s;
    vector<vector<int>> m1 = {{1, -1}, {-1, 1}};
    vector<vector<int>> m2 = {{ 1, 2, 3 }, {-1, -2, -3 }, {1, 2, 3}}; 
    return 0;
}