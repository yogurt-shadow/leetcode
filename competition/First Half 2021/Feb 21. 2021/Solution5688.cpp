#include<iostream>
#include<vector>

using namespace std;

class Solution5688 {
public:
    int longestPalindrome(string word1, string word2) {
        int size1 = word1.length(), size2 = word2.length(), size = size1 + size2;
        string word = word1 + word2;
        int ans = word[size1 - 1] == word[size1] ? 2 : 0;
        vector<vector<int>> dp(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i + 1 < size){
                dp[i][i + 1] = word[i] == word[i + 1] ? 2 : 1;
            }
        }
        for(int length = 3; length <= size; length++){
            for(int left = 0; left + length - 1 < size; left++){
                int right = left + length - 1;
                if(word[left] == word[right]){
                    dp[left][right] = dp[left + 1][right - 1] + 2;
                    if(left < size1 && right >= size1){
                        ans = max(ans, dp[left][right]);
                    }
                }
                else{
                    dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution5688 s;
    string s1 = "aazzlizfmn";
    string s2 = "nppqb";
    cout << s.longestPalindrome(s1, s2);
    return 0;
}