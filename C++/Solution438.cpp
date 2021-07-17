#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution438 {
public:
    bool check(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2){
        for(auto& ele: mp1){
            if(mp2[ele.first] != ele.second){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp1, mp2;
        for(auto ele: p){
            mp1[ele]++;
        }
        for(int i = 0; i < p.length(); i++){
            mp2[s[i]]++;
        }
        if(check(mp1, mp2)){
            ans.push_back(0);
        }
        for(int start = 1; start + p.length() <= s.length(); start++){
            mp2[s[start - 1]] --;
            mp2[s[start + p.length() - 1]]++;
            if(check(mp1, mp2)){
                ans.push_back(start);
            }
        }
        return ans;
    }
};