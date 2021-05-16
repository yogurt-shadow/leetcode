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
    string sortSentence(string s)
    {
        vector<string> ans(10);
        string cur = "";
        int ss = 0;
        for (auto ele : s)
        {
            if (ele == ' ')
            {
                int x = cur[cur.length() - 1] - '0';
                ss = max(ss, x);
                ans[x] = cur.substr(0, cur.length() - 1);
                cur = "";
            }
            else
            {
                cur += ele;
            }
        }
        int x = cur[cur.length() - 1] - '0';
        ss = max(ss, x);
        ans[x] = cur.substr(0, cur.length() - 1);
        cur = "";
        string res = "";
        for (int i = 1; i < ss; i++)
        {
            res += ans[i];
            res += " ";
        }
        res += ans[ss];
        return res;
    }
};