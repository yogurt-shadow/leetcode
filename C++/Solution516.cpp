#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

typedef long long ll;

class Solution516 {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.length();
        vector<vector<int>> dp(size, vector<int>(size));
        for(int i = size - 1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < size; j++){
                if(s[j] == s[i]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][size - 1];
    }
};