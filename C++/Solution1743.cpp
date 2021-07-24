#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;


class Solution1743 {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, unordered_set<int>> mp;
        for (auto ele : adjacentPairs)
        {
            mp[ele[0]].insert(ele[1]);
            mp[ele[1]].insert(ele[0]);
        }
        int cur = 0;
        for (auto ele : mp)
        {
            if (ele.second.size() == 1)
            {
                cur = ele.first;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(cur);
        unordered_set<int> st;
        st.insert(cur);
        while (ans.size() < adjacentPairs.size() + 1)
        {
            for (auto ele : mp[cur])
            {
                if (st.count(ele) == 0)
                {
                    cur = ele;
                    break;
                }
            }
            st.insert(cur);
            ans.push_back(cur);
        }
        return ans;
    }
};