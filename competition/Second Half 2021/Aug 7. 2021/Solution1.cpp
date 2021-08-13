#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
    string makeFancyString(string s)
    {
        string ans = "";
        char last = ' ';
        int cur = 0;
        for (auto ele : s)
        {
            if (ele == last)
            {
                cur++;
                if (cur >= 3)
                {
                    cur--;
                }
                else
                {
                    ans += ele;
                }
            }
            else
            {
                ans += ele;
                cur = 1;
                last = ele;
            }
        }
        return ans;
    }
};
