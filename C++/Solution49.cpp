#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(auto str: strs){
            string copy = str;
            sort(copy.begin(), copy.end());
            map[copy].push_back(str);
        }
        for(auto ele : map){
            res.push_back(ele.second);
        }
        return res;
    }
};