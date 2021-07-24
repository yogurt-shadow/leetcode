#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution5161 {
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        int ans = 0;
        unordered_set<char> st;
        for (auto ele : brokenLetters)
        {
            st.insert(ele);
        }
        string cur = "";
        for (auto ele : text)
        {
            if (ele == ' ')
            {
                bool have = true;
                for (auto ele2 : cur)
                {
                    if (st.count(ele2))
                    {
                        have = false;
                        break;
                    }
                }
                if (have)
                {
                    ans++;
                }
                cur = "";
            }
            else
            {
                cur += ele;
            }
        }
        bool have = true;
        //cout << cur << endl;
        for (auto ele2 : cur)
        {
            if (st.count(ele2))
            {
                //cout << 123 << endl;
                have = false;
                break;
            }
        }
        if (have)
        {
            ans++;
        }
        return ans;
    }
};