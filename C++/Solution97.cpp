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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<VII> VIII;

class Solution97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len3 != len1 + len2){
            return false;
        }
        VII dp(len1 + 1, VI(len2 + 1));
        dp[0][0] = 1;
        for(int i = 0; i < len1 + 1; i++){
            for(int j = 0; j < len2 + 1; j++){
                int cur = i + j - 1;
                if(i > 0){
                    dp[i][j] |= (dp[i - 1][j] && (s3[cur] == s1[i - 1]));
                }
                if(j > 0){
                    dp[i][j] |= (dp[i][j - 1] && (s3[cur] == s2[j - 1]));
                }
            }
        }
        return dp[len1][len2];
    }
};