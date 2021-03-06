#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution72 {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.length(), size2 = word2.length();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
        for(int i = 0; i <= size1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= size2; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(word1[i - 1] != word2[j - 1]){
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1] - 1, min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }   
        }
        return dp[size1][size2];
    }
};