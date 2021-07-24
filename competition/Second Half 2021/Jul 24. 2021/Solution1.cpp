#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution1{
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> mp;
        for (auto ele : s)
        {
            mp[ele]++;
        }
        int count = 0;
        for (auto ele : mp)
        {
            if (count == 0)
            {
                count = ele.second;
            }
            if (ele.second != count && ele.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}