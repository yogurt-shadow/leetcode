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

class Solution91 {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(!len){
            return 0;
        }
        vector<int> dp(len + 1);
        dp[0] = 1;
        for(int i = 0; i < len; i++){
            char cur = s[i];
            if(s[i] == '0'){
                if(i == 0){
                    return 0;
                }
                if(s[i - 1] == '1' || s[i - 1] == '2'){
                    dp[i + 1] = dp[i - 1];
                }
                else{
                    return 0;
                }
            }
            else{
                dp[i + 1] = dp[i];
                if(i >= 1){
                    string str = s.substr(i - 1, 2);
                    if(s[i - 1] != '0' && str <= "26"){
                        dp[i + 1] += dp[i - 1];
                    }
                }
            }
        } 
        return dp[len];
    }
};

int main(){
    cout << ("12" <= "26") << endl;
    cout << ("26" <= "26") << endl;
    cout << ("28" <= "26") << endl;
    return 0;
}