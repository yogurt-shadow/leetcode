#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution953 {
public:
    int mp[26];

    bool cmp(string str1, string str2){
        for(int i = 0; i < min(str1.length(), str2.length()); i++){
            if(mp[str1[i] - 'a'] > mp[str2[i] - 'a']){
                return true;
            }
            if(mp[str1[i] - 'a'] < mp[str2[i] - 'a']){
                return false;
            }
        }
        return str1.length() >= str2.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); i++){
            mp[order[i] - 'a'] = i;
        }
        for(int i = 0; i + 1 < words.size(); i++){
            if(!cmp(words[i + 1], words[i])){
                return false;
            }
        }
        return true;
    }
};