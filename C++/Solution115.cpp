#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

class Solution115 {
public:
    int numDistinct(string s, string t) {
        int size1 = s.length(), size2 = t.length();
        vector<vector<long long>> dp(size1 + 1, vector<long long>(size2 + 1));
        for(int i = 0; i <= size1; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= i && j <= size2; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[size1][size2];
    }
};

int main(){
    Solution115 s;
    string str1 = "babgbag";
    string str2 = "bag";
    cout << s.numDistinct(str1, str2);
    return 0;
}