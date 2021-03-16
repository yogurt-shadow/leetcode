#include<iostream>
#include<vector>
#include<algorithm>

#include<unordered_map>

using namespace std;

class LCP19 {
public:
    int minimumOperations(string leaves) {
        int size = leaves.size();
        vector<vector<int>> dp(3, vector<int>(size + 1));
        string three = leaves.substr(0, 3);
        dp[0][3] = diff(three, "rrr");
        dp[1][3] = min(diff(three, "ryy"), diff(three, "rry"));
        dp[2][3] = diff(three, "ryr");
        for(int i = 4; i <= size; i++){
            dp[0][i] = (leaves[i - 1] == 'r') ? dp[0][i - 1] : dp[0][i - 1] + 1;
            dp[1][i] = (leaves[i - 1] == 'y') ? min(dp[1][i - 1], dp[0][i - 1]) : min(dp[1][i - 1], dp[0][i - 1]) + 1;
            dp[2][i] = (leaves[i - 1] == 'r') ? min(dp[1][i - 1], dp[2][i - 1]) : min(dp[1][i - 1], dp[2][i - 1]) + 1;
        }
        return dp[2][size];
    }

    int diff(string str1, string str2){
        int res = 0;
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]){
                res++;
            }
        }
        return res;
    }
};