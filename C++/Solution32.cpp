#include<iostream>
#include<vector>

using namespace std;

class Solution32 {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size);
        for(int i = 1; i < size; i++){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                }
                else{
                    if(i - dp[i - 1] - 1>= 0){
                        if(s[i - dp[i - 1] - 1] == '('){
                            dp[i] =  i - dp[i - 1] - 2 >= 0 ? dp[i - 1] + 2 + dp[i - dp[i - 1] - 2] : dp[i - 1] + 2;
                        }
                    }
                }
            }
        }
        int len = 0;
        for(int i = 1; i < size; i++){
            len = max(len, dp[i]);
        }
        return len;
    }
};