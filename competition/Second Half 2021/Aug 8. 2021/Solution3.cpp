#include<iostream>
#include<vector>

using namespace std;
#define MAX 0x3f3f3f3f;

class Solution3 {
public:
    int minSwaps(string s)
    {
        int ans = 0;
        int deg = 0;
        for (auto ele : s)
        {
            if (ele == '[')
            {
                deg++;
            }
            else
            {
                deg--;
                if (deg < 0)
                {
                    deg = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};