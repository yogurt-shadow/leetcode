#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;

class Solution2 {
public:
    string small(string s, int x)
    {
        char a = x + '0';
        for (int i = 0; i < s.length(); i++)
        {
            if (a < s[i])
            {
                return s.substr(0, i) + a + s.substr(i, s.length() - i);
            }
        }
        return s + a;
    }

    string maxValue(string n, int x)
    {
        if (n[0] == '-')
        {
            string s = small(n.substr(1, n.length() - 1), x);
            return "-" + s;
        }
        char a = x + '0';
        for (int i = 0; i < n.length(); i++)
        {
            if (a > n[i])
            {
                return n.substr(0, i) + a + n.substr(i, n.length() - i);
            }
        }
        return n + a;
    }
};