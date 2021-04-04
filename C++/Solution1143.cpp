#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution1143 {
public:
    vector<vector<int>> dp;
    string str1, str2;

    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length();
        int size2 = text2.length();
        str1 = text1;
        str2 = text2;
        dp.resize(size1 + 1, vector<int>(size2 + 1, -1));
        return longest(size1, size2);
    }

    int longest(int size1, int size2){
        if(size1 == 0 || size2 == 0){
            return 0;
        }
        if(dp[size1][size2] != -1){
            return dp[size1][size2];
        }
        int len;
        if(str1[size1 - 1] == str2[size2 - 1]){
            len = 1 + longest(size1 - 1, size2 - 1);
        }
        else{
            len = max(longest(size1, size2 - 1), longest(size1 - 1, size2));
        }
        dp[size1][size2] = len;
        return len;
    }
};