#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool cmp(string str1, string str2){
    return str1.length() < str2.length();
}

class Solution1048 {
public:
    unordered_map<string, int> mp;

    bool check(string str1, string str2){
        if(str1.length() != str2.length()){
            return false;
        }
        int index1 = 0, index2 = 0;
        while(index1 < str1.length() && index2 < str2.length()){
            if(str1[index1] == str2[index2]){
                index1 ++;
                index2 ++;
            }
            else{
                index1 ++;
            }
        }
        return index2 == str2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(words.size(), 1);
        int ans = 1;
        for(int i = 0; i < words.size(); i++){
            string cur = words[i];
            for(int j = 0; j < cur.length(); j++){
                string str = cur.substr(0, j) + cur.substr(j + 1, cur.length() - j - 1);
                if(mp.count(str)){
                    dp[i] = max(dp[i], dp[mp[str]] + 1);
                    ans = max(ans, dp[i]);
                }
            }
            mp[cur] = i;
        }
        return ans;        
    }
};