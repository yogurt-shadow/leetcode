#include<iostream>
#include<vector>

using namespace std;

class Solution132 {
public:
    int minCut(string s) {
        vector<vector<int>> dp;
        int size = s.length();
        dp.resize(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i + 1 < size){
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 1;
                }
            }
        }
        for(int len = 3; len <= size; len++){
            for(int left = 0; left + len - 1 < size; left++){
                int right = left + len - 1;
                if(s[left] == s[right]){
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }
        }
        vector<int> f(size, INT_MAX);
        for(int i = 0; i < size; i++){
            if(dp[0][i]){
                f[i] = 0;
            }
            else{
                for(int j = 0; j < i; j++){
                    if(dp[j + 1][i]){
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[size - 1];
    }
};