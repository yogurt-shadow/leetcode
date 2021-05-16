#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution2
{
public:
    int minSwaps(string s)
    {
        vector<int> times(2, 0);
        for (auto ele : s)
        {
            times[ele - '0']++;
        }
        if (abs(times[1] - times[0]) > 1)
        {
            return -1;
        }
        int ans = INT_MAX;
        if (times[1] == times[0] + 1)
        {
            int diff = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (i % 2 == 1)
                {
                    if (s[i] == '1')
                        diff++;
                }
                else
                {
                    if (s[i] == '0')
                        diff++;
                }
            }
            return diff / 2;
        }
        if (times[0] == times[1] + 1)
        {
            int diff = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (i % 2 == 1)
                {
                    if (s[i] == '0')
                        diff++;
                }
                else
                {
                    if (s[i] == '1')
                        diff++;
                }
            }
            return diff / 2;
        }
        int diff1 = 0;
        int diff2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 1)
            {
                if (s[i] == '0')
                    diff1++;
                else
                    diff2++;
            }
            else
            {
                if (s[i] == '1')
                    diff1++;
                else
                    diff2++;
            }
        }
        return min(diff1, diff2) / 2;
    }
};


int main(){

    return 0;
}