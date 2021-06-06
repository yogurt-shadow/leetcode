#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution3 {
public:
    int minFlips(string s)
    {
        int cur = 0;
        int size = s.length();
        string str = "01";
        for (int i = 0; i < size; i++)
        {
            if (s[i] != str[i % 2])
            {
                cur++;
            }
        }
        int ans = min(cur, size - cur);
        if (size % 2 == 0)
        {
            return ans;
        }
        s = s + s;
        for (int i = 0; i < size; i++)
        {
            if (s[i + size] != str[(i + size) % 2])
            {
                cur++;
            }
            if (s[i] != str[i % 2])
            {
                cur--;
            }
            ans = min(ans, min(cur, size - cur));
        }
        return ans;
    }
};

int main(){

    
    return 0;
}