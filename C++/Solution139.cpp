#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long long ll;

class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto ele: wordDict){
            st.insert(ele);
        }
        int size = s.length();
        vector<int> dp(size + 1);
        dp[0] = 1;
        for(int i = 1; i <= size; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && st.count(s.substr(j, i - j))){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[size];
    }
};