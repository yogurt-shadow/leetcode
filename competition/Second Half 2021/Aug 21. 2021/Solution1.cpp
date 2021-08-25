#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1 {
public:
    int minTimeToType(string word)
    {
        int ans = 0;
        char cur = 'a';
        for (auto ele : word)
        {
            ans++;
            if (cur <= ele)
            {
                ans += min(ele - cur, 26 + cur - ele);
            }
            else
            {
                ans += min(cur - ele, 26 + ele - cur);
            }
            cur = ele;
        }
        return ans;
    }
};

int main(){
    Solution1 s;
    cout << s.minTimeToType("abc") << endl;
    cout << s.minTimeToType("bza") << endl;
    cout << s.minTimeToType("zjpc") << endl;
    return 0;
}