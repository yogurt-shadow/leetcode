#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution1 {
public:
    int getLucky(string s, int k)
    {
        int cur = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - 'a' + 1;
            cur += x % 10;
            cur += x / 10;
        }
        while (k > 1)
        {
            k--;
            int cur2 = 0;
            while (cur)
            {
                cur2 += cur % 10;
                cur = cur / 10;
            }
            cur = cur2;
        }
        return cur;
    }
};

int main(){

    return 0;
}