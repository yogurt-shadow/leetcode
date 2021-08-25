#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1716 {
public:
    int totalMoney(int n) {
        int ans = 0;
        int week = n / 7;
        ans += (49 + 7 * week) * week / 2;
        int left = n % 7;
        ans += left * week + (left + 1) * left / 2;
        return ans;
    }
};