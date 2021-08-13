#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<set>

using namespace std;
typedef long long ll;

class Solution91 {
public:
    int numDecodings(string s)
    {
        int size = s.length();
        vector<int> dp(size + 1);
        if (s[0] == '0')
        {
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= size; i++)
        {
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
            {
                dp[i] += dp[i - 2];
            }
            //cout << i << dp[i] << endl;
        }
        return dp[size];
    }
};

int main(){
    cout << ("12" <= "26") << endl;
    cout << ("26" <= "26") << endl;
    cout << ("28" <= "26") << endl;
    return 0;
}