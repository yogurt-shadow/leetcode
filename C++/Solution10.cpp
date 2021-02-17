#include<iostream>
#include<vector>

using namespace std;

class Solution10 {
public:
    string str1, str2;
    bool check(int x, int y){
        if(x == 0){
            return false;
        }
        return str2[y - 1] == '.' || str1[x - 1] == str2[y - 1];
    }

    bool isMatch(string s, string p) {
        str1 = s;
        str2 = p;
        int size1 = s.length();
        int size2 = p.length();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
        dp[0][0] = true;
        for(int i = 0; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(p[j - 1] == '*'){
                    if(check(i, j - 1)){
                        dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
                    }
                    else{
                        dp[i][j] = dp[i][j - 2];
                    }
                }
                else{
                    if(check(i, j)){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[size1][size2];
    }
};

int main(){
    vector<int> test(12);
    for(auto ele: test){
        cout << ele << " ";
    }
}