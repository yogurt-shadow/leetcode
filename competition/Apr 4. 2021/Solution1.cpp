#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


class Solution1{
public:
    string truncateSentence(string s, int k) {
        vector<string> vec1;
        string cur = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(cur != ""){
                    vec1.push_back(cur);
                    cur = "";
                }
            }
            else{
                cur += s[i];
            }
        }
        vec1.push_back(cur);
        cur = "";
        string res = "";
        for(int i = 0; i < k; i++){
            res += vec1[i];
            res += " ";
        }
        return res.substr(0, res.length() - 1);
    }
};