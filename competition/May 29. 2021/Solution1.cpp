#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include<queue>

using ll = long long;

using namespace std;

class Solution1 {
public:
    int countGoodSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i + 2 < s.length(); i++)
        {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
            {
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}