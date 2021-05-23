#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

class Solution1{
public:
    bool checkZeroOnes(string s)
    {
        int len1 = 0;
        int len2 = 0;
        int cur = 0;
        for (auto ele : s)
        {
            if (ele == '1')
            {
                if (cur >= 0)
                {
                    cur++;
                }
                else
                {
                    cur = 1;
                }
                len1 = max(len1, cur);
            }
            else
            {
                if (cur <= 0)
                {
                    cur--;
                }
                else
                {
                    cur = -1;
                }
                len2 = max(len2, abs(cur));
            }
        }
        return len1 > len2;
    }
};

int main(){
    
    
    return 0;
}