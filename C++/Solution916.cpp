#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;

class Solution916 {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> mp;
        for(auto str: words2){
            unordered_map<char, int> cur;
            for(auto ele: str){
                cur[ele]++;
            }
            merge(mp, cur);
        }
        for(auto str: words1){
            unordered_map<char, int> cur;
            for (auto ele : str){
                cur[ele]++;
            }
            if(contains(cur, mp)){
                ans.push_back(str);
            }
        }
        return ans;
    }

private:
    void merge(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2){
        for(auto ele: mp2){
            mp1[ele.first] = max(mp1[ele.first], ele.second);
        }
    }

    bool contains(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2){
        for(auto ele: mp2){
            if(mp1[ele.first] < ele.second){
                return false;
            }
        }
        return true;
    }
};