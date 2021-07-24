#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution10_02 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs)
        {
            string copy = str;
            sort(copy.begin(), copy.end());
            if (mp.count(copy))
            {
                auto &ele = mp[copy];
                ele.push_back(str);
            }
            else
            {
                vector<string> cur;
                cur.push_back(str);
                mp[copy] = cur;
            }
        }
        for (auto &ele : mp)
        {
            ans.push_back(ele.second);
        }
        return ans;
    }
};